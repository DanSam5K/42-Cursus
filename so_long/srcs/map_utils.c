/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:41:15 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/13 20:49:09 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Function to compares two strings character by character and returns the
//difference between the first two non-matching characters (in ASCII value)
int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_find_player(t_game_instance *game, int *start_row, int *start_col)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_init.rows_matrix)
	{
		j = 0;
		while (j < game->map_init.cols_matrix)
		{
			if (game->map_init.matrix[i][j] == 'P')
			{
				*start_row = i;
				*start_col = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	ft_check_path(t_game_instance *game, int **marked)
{
	int	row;
	int	col;
	int	exit;
	int	collectible;

	row = -1;
	exit = 0;
	collectible = 0;
	while (game->map_init.matrix[++row])
	{
		col = -1;
		while (game->map_init.matrix[row][++col])
		{
			if (game->map_init.matrix[row][col] == 'E' && marked[row][col] == 1)
				exit++;
			if (game->map_init.matrix[row][col] == 'C' && marked[row][col] == 1)
				collectible++;
		}
	}
	if (exit == 1 && collectible >= 1)
		return (1);
	return (0);
}

void	ft_mark_path(t_game_instance *game, int row, int col, int **marked)
{
	if ((row < 0 || row >= game->map_init.rows_matrix)
		&& (col < 0 || col >= game->map_init.cols_matrix))
		return ;
	if (game->map_init.matrix[row][col] != '1' && marked[row][col] != 1)
	{
		marked[row][col] = 1;
		ft_mark_path(game, row, col + 1, marked);
		ft_mark_path(game, row, col - 1, marked);
		ft_mark_path(game, row + 1, col, marked);
		ft_mark_path(game, row - 1, col, marked);
	}
}

int	ft_has_path(t_game_instance *game)
{
	int		**marked;
	int		valid_path;
	int		i;
	int		start_row;
	int		start_col;

	i = 0;
	valid_path = 1;
	marked = (int **)ft_calloc(game->map_init.rows_matrix, sizeof(int *));
	if (!marked)
		return (0);
	while (i < game->map_init.rows_matrix)
	{
		marked[i] = (int *)ft_calloc(game->map_init.cols_matrix, sizeof(int));
		if (!marked[i])
			return (0);
		i++;
	}
	ft_find_player(game, &start_row, &start_col);
	ft_mark_path(game, start_row, start_col, marked);
	valid_path = ft_check_path(game, marked);
	while (--i >= 0)
		free(marked[i]);
	free(marked);
	return (valid_path);
}
