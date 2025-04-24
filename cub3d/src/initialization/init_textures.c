/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:55:42 by baguiar-          #+#    #+#             */
/*   Updated: 2025/03/26 15:33:14 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_initialize_textures_data(t_texture_data *textures)
{
	if (!textures)
		return ;
	ft_memset(textures, 0, sizeof(t_texture_data));
	textures->size = TEXTURE_SIZE;
	textures->hex_floor = 0x0;
	textures->hex_ceiling = 0x0;
	textures->text_config.no_text_path = NULL;
	textures->text_config.so_text_path = NULL;
	textures->text_config.we_text_path = NULL;
	textures->text_config.ea_text_path = NULL;
}

void	ft_initialize_graphic_pixels(t_game_data *game_data)
{
	int		i;
	size_t	pixel_size;

	if (game_data->texture_pixels)
		ft_free_table((void **)game_data->texture_pixels);
	pixel_size = sizeof(*game_data->texture_pixels);
	game_data->texture_pixels = ft_calloc(game_data->win_height + 1,
			pixel_size);
	if (!game_data->texture_pixels)
		ft_clean_and_exit(game_data, ft_error_msg(NULL, ERR_MALLOC, 1));
	i = 0;
	while (i < game_data->win_height)
	{
		game_data->texture_pixels[i] = ft_calloc(game_data->win_width + 1,
				pixel_size);
		if (!game_data->texture_pixels[i])
			ft_clean_and_exit(game_data, ft_error_msg(NULL, ERR_MALLOC, 1));
		i++;
	}
}

void	ft_get_graphic_location(t_game_data *game_data, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_distance.ray_dir_x < 0)
			game_data->texture_data.config_found = DIR_WEST;
		else
			game_data->texture_data.config_found = DIR_EAST;
		return ;
	}
	if (ray->ray_distance.ray_dir_y > 0)
		game_data->texture_data.config_found = DIR_SOUTH;
	else
		game_data->texture_data.config_found = DIR_NORTH;
}

void	ft_update_graphic_pixels(t_game_data *game_data,
		t_texture_data *texture, t_ray *ray, int x)
{
	int			y;
	int			color;

	ft_get_graphic_location(game_data, ray);
	texture->x_dir = (int)(ray->ray_distance.wall_x * texture->size);
	if ((ray->side == 0 && ray->ray_distance.ray_dir_x < 0)
		|| (ray->side == 1 && ray->ray_distance.ray_dir_y > 0))
		texture->x_dir = texture->size - texture->x_dir - 1;
	texture->step = 1.0 * texture->size / ray->line_height;
	texture->pos = (ray->draw_start - game_data->win_height / 2
			+ ray->line_height / 2) * texture->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		texture->y_dir = (int)texture->pos & (texture->size - 1);
		texture->pos += texture->step;
		color = game_data->textures[texture->config_found]
		[texture->size * texture->y_dir + texture->x_dir];
		if (texture->config_found == DIR_NORTH
			|| texture->config_found == DIR_EAST)
			color = (color >> 1) & 8355711;
		if (color > 0)
			game_data->texture_pixels[y][x] = color;
		y++;
	}
}

void	ft_initialize_textures(t_game_data *game_data)
{
	char	*text_paths[4];
	int		i;

	text_paths[DIR_NORTH]
		= game_data->texture_data.text_config.no_text_path;
	text_paths[DIR_SOUTH]
		= game_data->texture_data.text_config.so_text_path;
	text_paths[DIR_WEST]
		= game_data->texture_data.text_config.we_text_path;
	text_paths[DIR_EAST]
		= game_data->texture_data.text_config.ea_text_path;
	game_data->textures = ft_calloc(5, sizeof * game_data->textures);
	if (!game_data->textures)
		ft_clean_and_exit(game_data, ft_error_msg(NULL, ERR_MALLOC, 1));
	i = -1;
	while (++i < 4)
	{
		game_data->textures[i] = ft_convert_xpm_to_img(game_data,
				text_paths[i]);
		if (!game_data->textures[i])
			ft_clean_and_exit(game_data,
				ft_error_msg(NULL, ERR_TEX_LOAD, 1));
	}
}
