/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:34:20 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/13 20:48:43 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Function to initializes the window and sets the init properties of the game
void	ft_initialize_game(t_game_instance *game_init)
{
	game_init->mlx_ptr = mlx_init();
	if (game_init->mlx_ptr == NULL)
		ft_error_init(38);
	game_init->game_data.count_movements = 0;
	ft_img_init(game_init);
	game_init->game_objs.player = game_init->game_objs.player_down;
	game_init->win_ptr = mlx_new_window(game_init->mlx_ptr,
			game_init->map_init.resolutions.set_map_width
			* CELL_SIZE, game_init->map_init.resolutions.set_map_height
			* CELL_SIZE, "SO LONG BLUE YELLOW STAR KING");
	if (game_init->win_ptr == NULL)
		ft_error_init(38);
}

// Function to loads the different game images from image files (XPM format)
void	ft_img_init(t_game_instance *game_init)
{
	ft_check_img(game_init, &game_init->game_objs.player_up,
		"textures/Player/walk_up.xpm");
	ft_check_img(game_init, &game_init->game_objs.player_down,
		"textures/Player/walk_down.xpm");
	ft_check_img(game_init, &game_init->game_objs.player_right,
		"textures/Player/walk_right.xpm");
	ft_check_img(game_init, &game_init->game_objs.player_left,
		"textures/Player/walk_left.xpm");
	ft_check_img(game_init, &game_init->game_objs.collectible,
		"textures/Collectibles/star.xpm");
	ft_check_img(game_init, &game_init->game_objs.floor,
		"textures/Tiles/mid_block.xpm");
	ft_check_img(game_init, &game_init->game_objs.exit_open,
		"textures/Exit/exit_open.xpm");
	ft_check_img(game_init, &game_init->game_objs.exit_close,
		"textures/Exit/exit_close.xpm");
	ft_check_img(game_init, &game_init->game_objs.wall,
		"textures/Tiles/simple_block.xpm");
}

void	ft_check_img(t_game_instance *game_init, void **image, char *path)
{
	int	width;
	int	height;

	*image = mlx_xpm_file_to_image(game_init->mlx_ptr, path, &width, &height);
	if (*image == NULL)
	{
		ft_error_init(1);
		ft_exit_program(game_init);
	}
}
