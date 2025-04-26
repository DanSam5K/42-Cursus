/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_detection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:21:26 by dsamuel           #+#    #+#             */
/*   Updated: 2025/03/28 09:21:43 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_valid_wall_position(t_game_data *game_data, double x, double y)
{
	return (game_data->map[(int)y][(int)x] == '0');
}

bool	is_within_map_bounds(t_game_data *game_data, double x, double y)
{
	return (!(x < 0.25 || x >= game_data->map_data.map_width - 1.25
			|| y < 0.25 || y >= game_data->map_data.map_height - 0.25));
}

bool	is_valid_position(t_game_data *game_data, double x, double y)
{
	return (is_within_map_bounds(game_data, x, y)
		&& is_valid_wall_position(game_data, x, y));
}

int	ft_validate_movement(t_game_data *game_data, double next_x, double next_y)
{
	int	has_moved;

	has_moved = 0;
	if (is_valid_position(game_data, next_x, game_data->player.y_pos))
	{
		game_data->player.x_pos = next_x;
		has_moved = 1;
	}
	if (is_valid_position(game_data, game_data->player.x_pos, next_y))
	{
		game_data->player.y_pos = next_y;
		has_moved = 1;
	}
	return (has_moved);
}
