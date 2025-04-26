/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:19:08 by dsamuel           #+#    #+#             */
/*   Updated: 2025/03/28 09:19:11 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_get_text_path(char *line, int j)
{
	int		len;
	int		i;
	char	*path;

	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	len = j;
	while (line[len] && (line[len] != ' ' && line[len] != '\t'))
		len++;
	path = malloc(sizeof(char) * (len - j + 1));
	if (!path)
		return (NULL);
	i = 0;
	while (line[j] && (line[j] != ' ' && line[j] != '\t' && line[j] != '\n'))
		path[i++] = line[j++];
	path[i] = '\0';
	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	if (line[j] && line[j] != '\n')
	{
		free(path);
		path = NULL;
	}
	return (path);
}

int	ft_fill_direction(t_texture_data *textures, char *line, int j)
{
	if (line[j + 2] && ft_isprint(line[j + 2]))
		return (STATUS_ERROR);
	if (line[j] == 'N' && line[j + 1] == 'O'
		&& !(textures->text_config.no_text_path))
		textures->text_config.no_text_path
			= ft_get_text_path(line, j + 2);
	else if (line[j] == 'S' && line[j + 1] == 'O'
		&& !(textures->text_config.so_text_path))
		textures->text_config.so_text_path
			= ft_get_text_path(line, j + 2);
	else if (line[j] == 'W' && line[j + 1] == 'E'
		&& !(textures->text_config.we_text_path))
		textures->text_config.we_text_path
			= ft_get_text_path(line, j + 2);
	else if (line[j] == 'E' && line[j + 1] == 'A'
		&& !(textures->text_config.ea_text_path))
		textures->text_config.ea_text_path
			= ft_get_text_path(line, j + 2);
	else
		return (STATUS_ERROR);
	return (STATUS_OK);
}

int	ft_handle_space_get_data(t_game_data *game_data, char **map, int i, int j)
{
	ft_skip_whitespace(map[i], &j);
	if (ft_isprint(map[i][j]) && !ft_isdigit(map[i][j]))
		return (ft_handle_texture_or_color(game_data, map, i, j));
	else if (ft_isdigit(map[i][j]))
	{
		if (ft_build_map(game_data, map, i) == STATUS_FAIL)
			return (ft_error_msg(game_data->map_data.path,
					ERR_INVALID_MAP, STATUS_FAIL));
		return (STATUS_OK);
	}
	return (STATUS_CONTINUE);
}

int	ft_get_gamefiles_data(t_game_data *game_data, char **map)
{
	int	i;
	int	j;
	int	result;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			result = ft_handle_space_get_data(game_data, map, i, j);
			if (result == STATUS_BREAK)
				break ;
			else if (result == STATUS_FAIL)
				return (STATUS_FAIL);
			else if (result == STATUS_OK)
				return (STATUS_OK);
			j++;
		}
		i++;
	}
	return (STATUS_OK);
}
