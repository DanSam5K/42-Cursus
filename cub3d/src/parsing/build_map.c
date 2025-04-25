/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 22:49:02 by baguiar-          #+#    #+#             */
/*   Updated: 2025/03/26 12:38:55 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_record_lines(t_game_data *game_data, char **file, int start_index)
{
	int	current_index;
	int	whitespace_index;

	current_index = start_index;
	while (file[current_index])
	{
		whitespace_index = 0;
		while (ft_isspace(file[current_index][whitespace_index]))
			whitespace_index++;
		if (file[current_index][whitespace_index] != '1')
			break ;
		current_index++;
	}
	game_data->map_data.end_found = current_index;
	return (current_index - start_index);
}

int	ft_fill_map_table(t_map_data *map_data, char **map_table, int index)
{
	int	row;
	int	col;

	map_data->map_width = ft_max_width(map_data, index);
	row = -1;
	while (++row < map_data->map_height)
	{
		map_table[row] = malloc(sizeof(char) * (map_data->map_width + 1));
		if (!map_table[row])
			return (ft_error_msg(NULL, ERR_MALLOC, STATUS_FAIL));
		col = 0;
		while (map_data->file[index][col] &&
				map_data->file[index][col] != '\n')
		{
			map_table[row][col] = map_data->file[index][col];
			col++;
		}
		while (col < map_data->map_width)
			map_table[row][col++] = '\0';
		index++;
	}
	map_table[row] = NULL;
	return (STATUS_OK);
}

int	ft_get_map_data(t_game_data *game_data, char **file, int i)
{
	game_data->map_data.map_height = ft_record_lines(game_data, file, i);
	game_data->map
		= malloc(sizeof(char *) * (game_data->map_data.map_height + 1));
	if (!game_data->map)
		return (ft_error_msg(NULL, ERR_MALLOC, STATUS_FAIL));
	if (ft_fill_map_table(&game_data->map_data, game_data->map, i)
		== STATUS_FAIL)
		return (STATUS_FAIL);
	return (STATUS_OK);
}

void	ft_convert_space_to_wall(t_game_data *game_data)
{
	int	row;
	int	col;
	int	line_length;

	row = -1;
	while (game_data->map[++row])
	{
		col = 0;
		while (ft_isspace(game_data->map[row][col]))
			col++;
		line_length = ft_strlen(game_data->map[row]);
		while (game_data->map[row][col])
		{
			if (game_data->map[row][col] == ' '
				&& col != line_length - 1)
				game_data->map[row][col] = '1';
			col++;
		}
	}
}

int	ft_build_map(t_game_data *game_data, char **file, int i)
{
	if (ft_get_map_data(game_data, file, i) == STATUS_FAIL)
		return (STATUS_FAIL);
	ft_convert_space_to_wall(game_data);
	return (STATUS_OK);
}
