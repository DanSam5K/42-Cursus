/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:22:30 by dsamuel           #+#    #+#             */
/*   Updated: 2025/03/28 09:22:33 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_rotation(t_game_data *game_data, double rotation_speed)
{
	t_player	*player;
	double		tmp_x;

	player = &game_data->player;
	tmp_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rotation_speed) - player->dir_y
		* sin(rotation_speed);
	player->dir_y = tmp_x * sin(rotation_speed) + player->dir_y
		* cos(rotation_speed);
	tmp_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rotation_speed) - player->plane_y
		* sin(rotation_speed);
	player->plane_y = tmp_x * sin(rotation_speed) + player->plane_y
		* cos(rotation_speed);
	return (1);
}

int	ft_rotate_player(t_game_data *game_data, double rotation_direction)
{
	int		moved;
	double	rotation_speed;

	moved = 0;
	rotation_speed = ROTATION_SPEED * rotation_direction;
	moved += ft_rotation(game_data, rotation_speed);
	return (moved);
}
