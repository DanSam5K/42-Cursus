/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:20:26 by dsamuel           #+#    #+#             */
/*   Updated: 2025/03/28 09:20:26 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_validate_rgb(int *rgb)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			return (ft_error_val(rgb[i], ERR_TEX_RGB_VAL, STATUS_FAIL));
		i++;
	}
	return (STATUS_OK);
}

unsigned long	ft_con_rgb_hex(int *rgb_tab)
{
	unsigned long	rgb_val;
	int				r;
	int				g;
	int				b;

	r = rgb_tab[0];
	g = rgb_tab[1];
	b = rgb_tab[2];
	rgb_val = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	return (rgb_val);
}

int	ft_validate_textures_map(t_game_data *game_data, t_texture_data *textures)
{
	if (!textures->text_config.no_text_path
		|| !textures->text_config.so_text_path
		|| !textures->text_config.we_text_path
		|| !textures->text_config.ea_text_path)
		return (ft_error_msg(game_data->map_data.path,
				ERR_TEX_MISSING, STATUS_FAIL));
	if (!textures->text_config.floor_color
		|| !textures->text_config.ceiling_color)
		return (ft_error_msg(game_data->map_data.path,
				ERR_COLOR_MISSING, STATUS_FAIL));
	if (ft_file_and_dir_checker(textures->text_config.no_text_path,
			false) == STATUS_FAIL
		|| ft_file_and_dir_checker(textures->text_config.so_text_path,
			false) == STATUS_FAIL
		|| ft_file_and_dir_checker(textures->text_config.we_text_path,
			false) == STATUS_FAIL
		|| ft_file_and_dir_checker(textures->text_config.ea_text_path,
			false) == STATUS_FAIL
		|| ft_validate_rgb(textures->text_config.floor_color) == STATUS_FAIL
		|| ft_validate_rgb(textures->text_config.ceiling_color) == STATUS_FAIL)
		return (STATUS_FAIL);
	textures->hex_floor = ft_con_rgb_hex(textures->text_config.floor_color);
	textures->hex_ceiling = ft_con_rgb_hex(textures->text_config.ceiling_color);
	return (STATUS_OK);
}
