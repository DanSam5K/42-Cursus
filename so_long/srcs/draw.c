/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:26:49 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/10 13:02:55 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Function to sets the image the corresponding cell on the game board
void	ft_set(t_game_instance *game_init, void *img, int wid, int hgt)
{
	int	cell_size;

	cell_size = CELL_SIZE;
	mlx_put_image_to_window(game_init->mlx_ptr, game_init->win_ptr,
		img, wid * cell_size, hgt * cell_size);
}

int	ft_map_draw(t_game_instance *game_init)
{
	int	row;
	int	column;

	row = -1;
	while (game_init->map_init.matrix[++row])
	{
		column = 0;
		while (game_init->map_init.matrix[row][column])
		{
			if (game_init->map_init.matrix[row][column] == WALL)
				ft_set(game_init, game_init->game_objs.wall, column, row);
			if (game_init->map_init.matrix[row][column] == EMPTY)
				ft_set(game_init, game_init->game_objs.floor, column, row);
			if (game_init->map_init.matrix[row][column] == PLAYER)
				ft_set(game_init, game_init->game_objs.player, column, row);
			ft_map_continues(game_init, column, row);
			if (game_init->map_init.matrix[row][column] == COLLECTIBLE)
				ft_set(game_init, game_init->game_objs.collectible,
					column, row);
			column++;
		}
	}
	return (0);
}

void	ft_map_continues(t_game_instance *game_init, int column, int row)
{
	if (game_init->map_init.matrix[row][column] == EXIT
		&& game_init->game_data.count_collectible == 0)
		ft_set(game_init, game_init->game_objs.exit_open, column, row);
	if (game_init->map_init.matrix[row][column] == EXIT
		&& game_init->game_data.count_collectible != 0)
		ft_set(game_init, game_init->game_objs.exit_close, column, row);
	return ;
}
