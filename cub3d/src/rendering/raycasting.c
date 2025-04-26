/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:22:55 by dsamuel           #+#    #+#             */
/*   Updated: 2025/03/28 09:22:57 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_initialize_raycasting_data(int x, t_ray *ray, t_player *player)
{
	ft_initialize_ray_data(ray);
	ray->ray_distance.camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray->ray_distance.ray_dir_x = player->dir_x + player->plane_x
		* ray->ray_distance.camera_x;
	ray->ray_distance.ray_dir_y = player->dir_y + player->plane_y
		* ray->ray_distance.camera_x;
	ray->map_x = (int)player->x_pos;
	ray->map_y = (int)player->y_pos;
	ray->ray_distance.delta_dist_x = fabs(1 / ray->ray_distance.ray_dir_x);
	ray->ray_distance.delta_dist_y = fabs(1 / ray->ray_distance.ray_dir_y);
}

void	ft_set_dda(t_ray *ray, t_player *player)
{
	if (ray->ray_distance.ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->ray_distance.side_dist_x = (player->x_pos - ray->map_x)
			* ray->ray_distance.delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->ray_distance.side_dist_x = (ray->map_x + 1.0 - player->x_pos)
			* ray->ray_distance.delta_dist_x;
	}
	if (ray->ray_distance.ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->ray_distance.side_dist_y = (player->y_pos - ray->map_y)
			* ray->ray_distance.delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->ray_distance.side_dist_y = (ray->map_y + 1.0 - player->y_pos)
			* ray->ray_distance.delta_dist_y;
	}
}

void	ft_perform_dda(t_game_data *game_data, t_ray *ray)
{
	int	target;

	target = 0;
	while (target == 0)
	{
		if (ray->ray_distance.side_dist_x < ray->ray_distance.side_dist_y)
		{
			ray->ray_distance.side_dist_x += ray->ray_distance.delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->ray_distance.side_dist_y += ray->ray_distance.delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0.25
			|| ray->map_x < 0.25
			|| ray->map_y > game_data->map_data.map_height - 0.25
			|| ray->map_x > game_data->map_data.map_width - 1.25)
			break ;
		else if (game_data->map[ray->map_y][ray->map_x] > '0')
			target = 1;
	}
}

void	ft_calculate_line_height(t_ray *ray, t_game_data *game_data,
			t_player *player)
{
	if (ray->side == 0)
		ray->ray_distance.wall_dist = (ray->ray_distance.side_dist_x
				- ray->ray_distance.delta_dist_x);
	else
		ray->ray_distance.wall_dist = (ray->ray_distance.side_dist_y
				- ray->ray_distance.delta_dist_y);
	ray->line_height = (int)(game_data->win_height
			/ ray->ray_distance.wall_dist);
	ray->draw_start = -(ray->line_height) / 2 + game_data->win_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + game_data->win_height / 2;
	if (ray->draw_end >= game_data->win_height)
		ray->draw_end = game_data->win_height - 1;
	if (ray->side == 0)
		ray->ray_distance.wall_x = player->y_pos + ray->ray_distance.wall_dist
			* ray->ray_distance.ray_dir_y;
	else
		ray->ray_distance.wall_x = player->x_pos + ray->ray_distance.wall_dist
			* ray->ray_distance.ray_dir_x;
	ray->ray_distance.wall_x -= floor(ray->ray_distance.wall_x);
}

int	ft_raycasting(t_player *player, t_game_data *game_data)
{
	t_ray	ray;
	int		x;

	x = 0;
	ray = game_data->ray;
	while (x < game_data->win_width)
	{
		ft_initialize_raycasting_data(x, &ray, player);
		ft_set_dda(&ray, player);
		ft_perform_dda(game_data, &ray);
		ft_calculate_line_height(&ray, game_data, player);
		ft_update_graphic_pixels(game_data, &game_data->texture_data, &ray, x);
		x++;
	}
	return (STATUS_OK);
}
