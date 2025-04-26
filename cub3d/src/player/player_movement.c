/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:22:21 by dsamuel           #+#    #+#             */
/*   Updated: 2025/03/28 09:22:23 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	ft_move_forward(t_game_data *game_data)
{
	double	new_x;
	double	new_y;

	new_x = game_data->player.x_pos + game_data->player.dir_x * MOVE_SPEED;
	new_y = game_data->player.y_pos + game_data->player.dir_y * MOVE_SPEED;
	return (ft_validate_movement(game_data, new_x, new_y));
}

int	ft_move_backward(t_game_data *game_data)
{
	double	new_x;
	double	new_y;

	new_x = game_data->player.x_pos - game_data->player.dir_x * MOVE_SPEED;
	new_y = game_data->player.y_pos - game_data->player.dir_y * MOVE_SPEED;
	return (ft_validate_movement(game_data, new_x, new_y));
}

int	ft_move_left(t_game_data *game_data)
{
	double	next_x;
	double	next_y;

	next_x = game_data->player.x_pos + game_data->player.dir_y * MOVE_SPEED;
	next_y = game_data->player.y_pos - game_data->player.dir_x * MOVE_SPEED;
	return (ft_validate_movement(game_data, next_x, next_y));
}

int	ft_move_right(t_game_data *game_data)
{
	double	next_x;
	double	next_y;

	next_x = game_data->player.x_pos - game_data->player.dir_y * MOVE_SPEED;
	next_y = game_data->player.y_pos + game_data->player.dir_x * MOVE_SPEED;
	return (ft_validate_movement(game_data, next_x, next_y));
}

int	ft_move_player(t_game_data *game_data)
{
	int	moved;

	moved = 0;
	if (game_data->player.movement.move_y == 1)
		moved += ft_move_forward(game_data);
	if (game_data->player.movement.move_y == -1)
		moved += ft_move_backward(game_data);
	if (game_data->player.movement.move_x == -1)
		moved += ft_move_left(game_data);
	if (game_data->player.movement.move_x == 1)
		moved += ft_move_right(game_data);
	if (game_data->player.movement.rotate != 0)
		moved += ft_rotate_player(game_data, game_data->player.movement.rotate);
	return (moved);
}
