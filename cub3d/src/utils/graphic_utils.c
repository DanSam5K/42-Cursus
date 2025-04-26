/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:48:39 by dsamuel           #+#    #+#             */
/*   Updated: 2025/03/28 09:48:41 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_image_pixel(t_img_data *image, int x, int y, int color_val)
{
	int	pixel;

	pixel = y * (image->size_line / 4) + x;
	image->addr[pixel] = color_val;
}

int	*ft_move_to_rgb_contents(char **rgb_to_convert, int *rgb)
{
	int		i;

	i = -1;
	while (rgb_to_convert[++i])
	{
		rgb[i] = ft_atoi(rgb_to_convert[i]);
		if (rgb[i] == -1 || ft_comfirm_digit_absence(rgb_to_convert[i]) == true)
		{
			ft_free_table((void **)rgb_to_convert);
			free(rgb);
			return (0);
		}
	}
	ft_free_table((void **)rgb_to_convert);
	return (rgb);
}

int	*ft_compose_rgb_colors(char *line)
{
	char	**rgb_to_convert;
	int		*rgb;
	int		count;

	rgb_to_convert = ft_split(line, ',');
	count = 0;
	while (rgb_to_convert[count])
		count++;
	if (count != 3)
	{
		ft_free_table((void **)rgb_to_convert);
		return (0);
	}
	rgb = malloc(sizeof(int) * 3);
	if (!rgb)
	{
		ft_error_msg(NULL, ERR_MALLOC, 0);
		return (0);
	}
	return (ft_move_to_rgb_contents(rgb_to_convert, rgb));
}

int	ft_fill_rgb_color(t_game_data *game_data, t_texture_data *textures,
	char *line, int j)
{
	if (line[j + 1] && ft_isprint(line[j + 1]))
		return (ft_error_msg(game_data->map_data.path, ERR_FLOOR_CEILING,
				STATUS_ERROR));
	if (!textures->text_config.ceiling_color && line[j] == 'C')
	{
		textures->text_config.ceiling_color
			= ft_compose_rgb_colors(line + j + 1);
		if (textures->text_config.ceiling_color == 0)
			return (ft_error_msg(game_data->map_data.path, ERR_COLOR_CEILING,
					STATUS_ERROR));
	}
	else if (!textures->text_config.floor_color && line[j] == 'F')
	{
		textures->text_config.floor_color = ft_compose_rgb_colors(line + j + 1);
		if (textures->text_config.floor_color == 0)
			return (ft_error_msg(game_data->map_data.path, ERR_COLOR_FLOOR,
					STATUS_ERROR));
	}
	else
		return (ft_error_msg(game_data->map_data.path, ERR_FLOOR_CEILING,
				STATUS_ERROR));
	return (STATUS_OK);
}

int	ft_handle_texture_or_color(t_game_data *game_data,
				char **map, int i, int j)
{
	if (map[i][j + 1] && ft_isprint(map[i][j + 1])
		&& !ft_isdigit(map[i][j + 1]))
	{
		if (ft_fill_direction(&game_data->texture_data, map[i], j)
			== STATUS_ERROR)
			return (ft_error_msg(game_data->map_data.path,
					ERR_TEX_INVALID, STATUS_ERROR));
		return (STATUS_BREAK);
	}
	else
	{
		if (ft_fill_rgb_color(game_data, &game_data->texture_data,
				map[i], j) == STATUS_ERROR)
			return (STATUS_FAIL);
		return (STATUS_BREAK);
	}
}
