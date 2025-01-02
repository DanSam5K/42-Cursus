/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:28:49 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/13 12:47:26 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Function to free() and quit the program
int	ft_exit_program(t_game_instance *game_init)
{
	ft_printf("Closing the window and program..\n");
	ft_free_img(game_init);
	ft_free_map(game_init);
	ft_cleanup(game_init);
	mlx_destroy_window(game_init->mlx_ptr, game_init->win_ptr);
	mlx_destroy_display(game_init->mlx_ptr);
	free(game_init->mlx_ptr);
	exit(0);
	return (0);
}

// Function to free() and reset the game (start in the same point)
void	ft_reset_game(t_game_instance *game_init)
{
	ft_printf("\nThe game has been reset, good luck.\n");
	ft_free_img(game_init);
	ft_free_map(game_init);
	free(game_init->res_init.set_name_window);
	free(game_init->res_init.set_name_map);
	mlx_destroy_window(game_init->mlx_ptr, game_init->win_ptr);
	mlx_destroy_display(game_init->mlx_ptr);
	free(game_init->mlx_ptr);
	main(game_init->argc_tmp, game_init->argv_tmp);
}

// Function to free the name in window
void	ft_cleanup(t_game_instance *game_init)
{
	if (game_init->res_init.set_name_window != NULL)
	{
		free(game_init->res_init.set_name_window);
		game_init->res_init.set_name_window = NULL;
	}
	if (game_init->res_init.set_name_map != NULL)
	{
		free(game_init->res_init.set_name_map);
		game_init->res_init.set_name_map = NULL;
	}
}
