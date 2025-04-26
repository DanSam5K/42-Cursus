/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:18:40 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/09 21:11:22 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_get_total_lines(char *path)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error_msg(path, strerror(errno), errno);
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			line_count++;
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (line_count);
}

void	ft_fill_table(int row, int column, int i, t_game_data *game_data)
{
	char	*line;

	line = get_next_line(game_data->map_data.fd);
	while (line != NULL)
	{
		game_data->map_data.file[row] = ft_calloc(ft_strlen(line) + 1,
				sizeof(char));
		if (!game_data->map_data.file[row])
		{
			ft_error_msg(NULL, ERR_MALLOC, 0);
			return (ft_free_table((void **)game_data->map_data.file));
		}
		while (line[i] != '\0')
			game_data->map_data.file[row][column++] = line[i++];
		game_data->map_data.file[row++][column] = '\0';
		column = 0;
		i = 0;
		free(line);
		line = get_next_line(game_data->map_data.fd);
	}
	game_data->map_data.file[row] = NULL;
}

void	ft_parse_game_data(char *path, t_game_data *game_data)
{
	int		row;
	int		i;
	size_t	column;

	i = 0;
	row = 0;
	column = 0;
	game_data->map_data.line_count = ft_get_total_lines(path);
	game_data->map_data.path = path;
	game_data->map_data.file = ft_calloc(game_data->map_data.line_count
			+ 1, sizeof(char *));
	if (!(game_data->map_data.file))
	{
		ft_error_msg(NULL, ERR_MALLOC, 0);
		return ;
	}
	game_data->map_data.fd = open(path, O_RDONLY);
	if (game_data->map_data.fd < 0)
		ft_error_msg(path, strerror(errno), STATUS_FAIL);
	else
	{
		ft_fill_table(row, column, i, game_data);
		close(game_data->map_data.fd);
	}
}

int	ft_parse_arguments(t_game_data *game_data, char **argv)
{
	if (ft_file_and_dir_checker(argv[1], true) == STATUS_FAIL)
		ft_clean_and_exit(game_data, STATUS_FAIL);
	ft_parse_game_data(argv[1], game_data);
	if (ft_get_gamefiles_data(game_data, game_data->map_data.file)
		== STATUS_FAIL)
		return (ft_free_game_data(game_data));
	if (ft_validate_map(game_data, game_data->map) == STATUS_FAIL)
		return (ft_free_game_data(game_data));
	if (ft_validate_textures_map(game_data, &game_data->texture_data)
		== STATUS_FAIL)
		return (ft_free_game_data(game_data));
	ft_initialize_player_direction(game_data);
	return (0);
}

int	ft_exit_game(t_game_data *game_data)
{
	ft_clean_and_exit(game_data, 0);
	return (0);
}
