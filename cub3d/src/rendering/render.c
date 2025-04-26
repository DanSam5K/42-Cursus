/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:23:24 by dsamuel           #+#    #+#             */
/*   Updated: 2025/03/28 09:23:24 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_frame_image_pixel(t_game_data *game_data,
	t_img_data *image, int x, int y)
{
	if (game_data->texture_pixels[y][x] > 0)
		ft_set_image_pixel(image, x, y, game_data->texture_pixels[y][x]);
	else if (y < game_data->win_height / 2)
		ft_set_image_pixel(image, x, y, game_data->texture_data.hex_ceiling);
	else if (y < game_data->win_height - 1)
		ft_set_image_pixel(image, x, y, game_data->texture_data.hex_floor);
}

void	ft_generate_render_frame(t_game_data *game_data)
{
	t_img_data	image;
	int			x;
	int			y;

	image.img = NULL;
	ft_initialize_image(game_data, &image, game_data->win_width,
		game_data->win_height);
	y = 0;
	while (y < game_data->win_height)
	{
		x = 0;
		while (x < game_data->win_width)
		{
			ft_set_frame_image_pixel(game_data, &image, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game_data->mlx, game_data->win, image.img, 0, 0);
	mlx_destroy_image(game_data->mlx, image.img);
}

void	ft_generate_render_raycast(t_game_data *game_data)
{
	ft_initialize_graphic_pixels(game_data);
	ft_initialize_ray_data(&game_data->ray);
	ft_raycasting(&game_data->player, game_data);
	ft_generate_render_frame(game_data);
}

void	ft_generate_render_images(t_game_data *game_data)
{
	ft_generate_render_raycast(game_data);
}

int	ft_render(t_game_data *game_data)
{
	game_data->player.movement.moved += ft_move_player(game_data);
	if (game_data->player.movement.moved == 0)
		return (0);
	ft_generate_render_images(game_data);
	return (0);
}
