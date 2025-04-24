/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:55:11 by baguiar-          #+#    #+#             */
/*   Updated: 2025/03/25 12:55:15 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_initialize_img_data(t_img_data *image)
{
	ft_memset(image, 0, sizeof(t_img_data));
}

void	ft_init_ray_fpoint(t_ray_fpoint *ray_fpoint)
{
	if (ray_fpoint)
		ft_memset(ray_fpoint, 0, sizeof(t_ray_fpoint));
}

void	ft_initialize_ray_data(t_ray *ray)
{
	if (ray)
	{
		ft_memset(ray, 0, sizeof(t_ray));
		ft_init_ray_fpoint(&ray->ray_distance);
	}
}

void	ft_initialize_map_data(t_map_data *map_data)
{
	if (map_data)
		ft_memset(map_data, 0, sizeof(t_map_data));
}

void	ft_initialize_data(t_game_data *game_data)
{
	if (game_data)
	{
		ft_memset(game_data, 0, sizeof(t_game_data));
		game_data->win_height = SCREEN_HEIGHT;
		game_data->win_width = SCREEN_WIDTH;
		ft_initialize_player_data(&game_data->player);
		ft_initialize_map_data(&game_data->map_data);
		ft_initialize_textures_data(&game_data->texture_data);
	}
}
