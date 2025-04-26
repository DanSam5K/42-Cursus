/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:55:32 by baguiar-          #+#    #+#             */
/*   Updated: 2025/03/25 12:55:34 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_initialize_player_data(t_player *player)
{
	if (!player)
		return ;
	ft_memset(player, 0, sizeof(t_player));
	player->movement.direction = '\0';
}

void	ft_initialize_player_direction(t_game_data *game_data)
{
	ft_initialize_movemement_direction(&game_data->player);
}
