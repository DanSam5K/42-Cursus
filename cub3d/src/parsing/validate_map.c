/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:19:28 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/15 11:16:32 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_validate_horizontal_boundaries(char **map_table, int i, int j)
{
	char	*trimmed_row;

	if (!map_table || !map_table[i])
		return (STATUS_FAIL);
	trimmed_row = ft_strtrim_whitespace(map_table[i]);
	if (!trimmed_row)
		return (STATUS_FAIL);
	while (trimmed_row[j])
	{
		if (trimmed_row[j] != '1')
		{
			free(trimmed_row);
			return (STATUS_FAIL);
		}
		j++;
	}
	free(trimmed_row);
	return (STATUS_OK);
}

int	ft_validate_map_boundaries(t_map_data *map_data, char **map_table)
{
	int		i;
	char	*trimmed_row;

	if (ft_validate_horizontal_boundaries(map_table, 0, 0) == STATUS_FAIL)
		return (STATUS_FAIL);
	i = 1;
	while (i < (map_data->map_height - 1))
	{
		trimmed_row = ft_strtrim_whitespace(map_table[i]);
		if (!trimmed_row || trimmed_row[0] != '1'
			|| trimmed_row[ft_strlen(trimmed_row) - 1] != '1')
		{
			free(trimmed_row);
			return (STATUS_FAIL);
		}
		free(trimmed_row);
		i++;
	}
	if (ft_validate_horizontal_boundaries(map_table, i, 0) == STATUS_FAIL)
		return (STATUS_FAIL);
	return (STATUS_OK);
}

int	ft_validate_map_components(t_game_data *game_data, char **map_table)
{
	int		row;
	char	*trimmed_row;

	row = 0;
	game_data->player.movement.direction = '0';
	while (map_table[row] != NULL)
	{
		trimmed_row = ft_strtrim_whitespace(map_table[row]);
		if (!trimmed_row)
			return (STATUS_FAIL);
		if (ft_validate_map_row(game_data, trimmed_row) == STATUS_FAIL)
		{
			free(trimmed_row);
			return (STATUS_FAIL);
		}
		free(trimmed_row);
		row++;
	}
	return (STATUS_OK);
}

int	ft_validate_map_end_reached(t_map_data *map)
{
	int		i;
	char	*trimmed_row;

	i = map->end_found;
	while (map->file[i])
	{
		trimmed_row = ft_strtrim_whitespace(map->file[i]);
		if (!trimmed_row)
			return (STATUS_FAIL);
		if (ft_strlen(trimmed_row) > 0)
		{
			free(trimmed_row);
			return (STATUS_FAIL);
		}
		free(trimmed_row);
		i++;
	}
	return (STATUS_OK);
}

int	ft_validate_map(t_game_data *game_data, char **map_table)
{
	if (!game_data->map)
		return (ft_error_msg(game_data->map_data.path,
				ERR_MAP_MISSING, STATUS_FAIL));
	if (ft_validate_map_boundaries(&game_data->map_data, map_table)
		== STATUS_FAIL)
		return (ft_error_msg(game_data->map_data.path,
				ERR_MAP_NO_WALLS, STATUS_FAIL));
	if (game_data->map_data.map_height < 3)
		return (ft_error_msg(game_data->map_data.path,
				ERR_MAP_TOO_SMALL, STATUS_FAIL));
	if (ft_validate_map_components(game_data, map_table) == STATUS_FAIL)
		return (STATUS_FAIL);
	if (ft_validate_player_position(game_data, map_table) == STATUS_FAIL)
		return (STATUS_FAIL);
	if (ft_validate_map_end_reached(&game_data->map_data) == STATUS_FAIL)
		return (ft_error_msg(game_data->map_data.path, ERR_MAP_LAST,
				STATUS_FAIL));
	return (STATUS_OK);
}
