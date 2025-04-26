/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:40:17 by baguiar-          #+#    #+#             */
/*   Updated: 2025/03/25 14:40:21 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_set_north_direction(t_player *player)
{
	player->dir_x = 0;
	player->dir_y = -1;
	player->plane_x = 0.66;
	player->plane_y = 0;
}

static void	ft_set_south_direction(t_player *player)
{
	player->dir_x = 0;
	player->dir_y = 1;
	player->plane_x = -0.66;
	player->plane_y = 0;
}

static void	ft_set_east_direction(t_player *player)
{
	player->dir_x = 1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
}

static void	ft_set_west_direction(t_player *player)
{
	player->dir_x = -1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = -0.66;
}

void	ft_initialize_movemement_direction(t_player *player)
{
	if (!player)
		return ;
	if (player->movement.direction == 'N')
		ft_set_north_direction(player);
	else if (player->movement.direction == 'S')
		ft_set_south_direction(player);
	else if (player->movement.direction == 'E')
		ft_set_east_direction(player);
	else if (player->movement.direction == 'W')
		ft_set_west_direction(player);
}
