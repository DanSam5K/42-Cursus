/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_player_position.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:20:06 by dsamuel           #+#    #+#             */
/*   Updated: 2025/03/28 09:20:06 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_validate_position(t_game_data *game_data, char **map_table)
{
	int	i;
	int	j;

	i = (int)game_data->player.y_pos;
	j = (int)game_data->player.x_pos;
	if (i <= 0 || j <= 0 || !map_table[i + 1] || !map_table[i - 1]
		|| (int)ft_strlen(map_table[i]) <= j
		|| (int)ft_strlen(map_table[i - 1]) <= j
		|| (int)ft_strlen(map_table[i + 1]) <= j)
		return (STATUS_FAIL);
	if (ft_strlen(map_table[i - 1]) < (size_t)j
		|| ft_strlen(map_table[i + 1]) < (size_t)j
		|| ft_empty_char(map_table[i][j - 1]) == STATUS_OK
		|| ft_empty_char(map_table[i][j + 1]) == STATUS_OK
		|| ft_empty_char(map_table[i - 1][j]) == STATUS_OK
		|| ft_empty_char(map_table[i + 1][j]) == STATUS_OK)
		return (STATUS_FAIL);
	return (STATUS_OK);
}

int	ft_validate_player_position(t_game_data *game_data, char **map_table)
{
	if (ft_check_player_direction(game_data) == STATUS_FAIL)
		return (STATUS_FAIL);
	if (ft_find_and_set_player_position(game_data, map_table) == STATUS_FAIL)
		return (ft_error_msg(game_data->map_data.path,
				ERR_PLAYER_POS, STATUS_FAIL));
	if (ft_validate_position(game_data, map_table) == STATUS_FAIL)
		return (ft_error_msg(game_data->map_data.path,
				ERR_PLAYER_POS, STATUS_FAIL));
	return (STATUS_OK);
}

int	ft_handle_player_direction(t_game_data *game_data, char current_char)
{
	if (ft_strchr("NSEW", current_char))
	{
		if (game_data->player.movement.direction != '0')
			return (ft_error_msg(game_data->map_data.path,
					ERR_NUM_PLAYER, STATUS_FAIL));
		game_data->player.movement.direction = current_char;
	}
	return (STATUS_OK);
}

int	ft_check_player_direction(t_game_data *game_data)
{
	if (game_data->player.movement.direction == '0')
		return (ft_error_msg(game_data->map_data.path,
				ERR_PLAYER_DIR, STATUS_FAIL));
	return (STATUS_OK);
}

int	ft_find_and_set_player_position(t_game_data *game_data,
											char **map_table)
{
	int	row;
	int	col;

	row = 0;
	while (map_table[row])
	{
		col = 0;
		while (map_table[row][col])
		{
			if (ft_strchr("NSEW", map_table[row][col]))
			{
				game_data->player.x_pos = (double)col + 0.5;
				game_data->player.y_pos = (double)row + 0.5;
				map_table[row][col] = '0';
				return (STATUS_OK);
			}
			col++;
		}
		row++;
	}
	return (STATUS_FAIL);
}
