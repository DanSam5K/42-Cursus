/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:30:09 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/13 12:02:00 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Function to free the matrix[][]
void	ft_free_map(t_game_instance *game_init)
{
	int	i;

	if (game_init->map_init.matrix == NULL)
		return ;
	i = 0;
	while (game_init->map_init.matrix[i])
	{
		free(game_init->map_init.matrix[i]);
		i++;
	}
	free(game_init->map_init.matrix);
	game_init->map_init.matrix = NULL;
	return ;
}

// Function to free all images.xpm
void	ft_free_img(t_game_instance *game_init)
{
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.player_up);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.player_left);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.player_right);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.player_down);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.collectible);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.exit_open);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.exit_close);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.wall);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.floor);
	game_init->game_objs = (t_game_objs){0};
}
