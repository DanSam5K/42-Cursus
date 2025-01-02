/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:36:13 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/13 12:28:28 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Function to calculate the dimensions of the game map by counting
//		the number of rows, columns and matrix
int	ft_map_dimensions(t_game_instance *game_init)
{
	game_init->map_init.cols_matrix = get_cols_count(&game_init->map_init);
	if (game_init->map_init.cols_matrix == 0)
		return (0);
	return (get_rows_count(game_init));
}

int	get_cols_count(t_map_data *map_init)
{
	char	*row;
	int		cols_count;

	row = map_init->matrix[0];
	cols_count = 0;
	while (*row && *row != '\n')
	{
		cols_count++;
		row++;
	}
	return (cols_count);
}

int	get_rows_count(t_game_instance *game_init)
{
	int	row_index;
	int	row_len;

	row_index = 0;
	while (game_init->map_init.matrix[row_index])
	{
		row_len = ft_strlen(game_init->map_init.matrix[row_index])
			- (game_init->map_init.matrix[row_index]
			[ft_strlen(game_init->map_init.matrix[row_index]) - 1] == '\n');
		if (row_len != game_init->map_init.cols_matrix)
		{
			game_init->map_init.rows_matrix = 0;
			return (0);
		}
		game_init->map_init.rows_matrix++;
		row_index++;
	}
	game_init->map_init.size_matrix = game_init->map_init.rows_matrix
		* game_init->map_init.cols_matrix;
	game_init->map_init.resolutions.set_map_width
		= game_init->map_init.cols_matrix;
	game_init->map_init.resolutions.set_map_height
		= game_init->map_init.rows_matrix;
	return (1);
}

// Function to checks if the map has a valid .ber extension and path/
int	ft_map_extension(char *map)
{
	char		*extension;
	char		*file_extension;
	static int	file_count;

	file_count = 0;
	extension = ".ber";
	file_extension = ft_strrchr(map, '.');
	if (map[ft_strlen(map) - 1] == '/')
	{
		ft_error_map(21);
		return (0);
	}
	else if (!file_extension || !ft_strcmp(file_extension, ""))
		return (0);
	else if (file_extension && !ft_strcmp(file_extension, extension))
	{
		if (file_count >= MAX_FILES)
			return (0);
		file_count++;
	}
	else
		return (0);
	return (1);
}
