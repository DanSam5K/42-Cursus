/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:21:56 by dsamuel           #+#    #+#             */
/*   Updated: 2025/03/28 09:21:56 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_handle_key_press(int key_code, t_game_data *game_data)
{
	if (key_code == XK_Escape)
		ft_exit_game(game_data);
	if (key_code == XK_Left)
		game_data->player.movement.rotate -= 1;
	if (key_code == XK_Right)
		game_data->player.movement.rotate += 1;
	if (key_code == XK_w)
		game_data->player.movement.move_y = 1;
	if (key_code == XK_a)
		game_data->player.movement.move_x = -1;
	if (key_code == XK_s)
		game_data->player.movement.move_y = -1;
	if (key_code == XK_d)
		game_data->player.movement.move_x = 1;
	return (0);
}

int	ft_handle_key_release(int key_code, t_game_data *game_data)
{
	if (key_code == XK_Escape)
		ft_exit_game(game_data);
	if (key_code == XK_w && game_data->player.movement.move_y == 1)
		game_data->player.movement.move_y = 0;
	if (key_code == XK_s && game_data->player.movement.move_y == -1)
		game_data->player.movement.move_y = 0;
	if (key_code == XK_a && game_data->player.movement.move_x == -1)
		game_data->player.movement.move_x += 1;
	if (key_code == XK_d && game_data->player.movement.move_x == 1)
		game_data->player.movement.move_x -= 1;
	if (key_code == XK_Left && game_data->player.movement.rotate <= 1)
		game_data->player.movement.rotate = 0;
	if (key_code == XK_Right && game_data->player.movement.rotate >= -1)
		game_data->player.movement.rotate = 0;
	return (0);
}

void	ft_adjust_mouse_position(t_game_data *game_data, int x, int y)
{
	if (x > game_data->win_width -20)
	{
		x = 20;
		mlx_mouse_move(game_data->mlx, game_data->win, x, y);
	}
	if (x < 20)
	{
		x = game_data->win_width - 20;
		mlx_mouse_move(game_data->mlx, game_data->win, x, y);
	}
}

int	ft_handle_mouse_motion(int x, int y, t_game_data *game_data)
{
	static int	old_x = SCREEN_WIDTH / 2;

	ft_adjust_mouse_position(game_data, x, y);
	if (x == old_x)
		return (0);
	else if (x < old_x)
		game_data->player.movement.moved += ft_rotate_player(game_data, -1);
	else if (x > old_x)
		game_data->player.movement.moved += ft_rotate_player(game_data, 1);
	old_x = x;
	return (0);
}

void	ft_setup_input_listeners(t_game_data *game_data)
{
	mlx_hook(game_data->win, ClientMessage, NoEventMask, ft_exit_game,
		game_data);
	mlx_hook(game_data->win, KeyPress, KeyPressMask, ft_handle_key_press,
		game_data);
	mlx_hook(game_data->win, KeyRelease, KeyReleaseMask, ft_handle_key_release,
		game_data);
	mlx_hook(game_data->win, MotionNotify, PointerMotionMask,
		ft_handle_mouse_motion, game_data);
}
