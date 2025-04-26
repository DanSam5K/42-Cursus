/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:27:42 by baguiar-          #+#    #+#             */
/*   Updated: 2025/04/15 11:17:14 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <X11/keysym.h>
# include <X11/X.h>

# include "libft.h"
# include "mlx.h"
# include "color_tools.h"

// Screen dimensions
# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720

// Texture size
# define TEXTURE_SIZE 64

// Movement and rotation speeds
# define MOVE_SPEED 0.1
# define ROTATION_SPEED 0.05

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

//

// Error messages
# define ERR_USAGE "Usage: ./cub3d <path/to/map.cub>"
# define ERR_FILE_NOT_CUB "Error: The file is not a .cub file"
# define ERR_FILE_NOT_XPM "Error: The texture is not an .xpm file"
# define ERR_FILE_IS_DIR "Error: The specified path is a directory"
# define ERR_FLOOR_CEILING "Error: Invalid RGB color(s) for floor/ceiling"
# define ERR_COLOR_FLOOR "Error: Invalid RGB color for floor"
# define ERR_COLOR_CEILING "Error: Invalid RGB color for ceiling"
# define ERR_INVALID_MAP "Error: The map description is incorrect or incomplete"
# define ERR_INV_LETTER "Error: The map contains an invalid character"
# define ERR_NUM_PLAYER "Error: The map contains more than one player"
# define ERR_TEX_RGB_VAL "Error: RGB value out of range (between 0 and 255)"
# define ERR_TEX_MISSING "Error: One or more textures missing"
# define ERR_TEX_INVALID "Error: One or more textures invalid"
# define ERR_TEX_LOAD "Error: One or more textures could not be loaded"
# define ERR_COLOR_MISSING "Error: One or more colors missing"
# define ERR_MAP_MISSING "Error: The map is missing from the file"
# define ERR_MAP_TOO_SMALL "Error: The map must be at least 3 lines high"
# define ERR_MAP_NO_WALLS "Error: The map is not fully enclosed by walls"
# define ERR_MAP_LAST "Error: The map is not the last element in file"
# define ERR_PLAYER_POS "Error: Invalid player starting position"
# define ERR_PLAYER_DIR "Error: Map lacks a player position (N, S, E or W)"
# define ERR_MALLOC "Error: Failed to allocate memory"
# define ERR_MLX_START "Error: Failed to start mlx"
# define ERR_MLX_WIN "Error: Failed to create mlx window"
# define ERR_MLX_IMG "Error: Failed to create mlx image"

typedef struct s_img_data
{
	int		pixel_bits;
	int		size_line;
	int		endian;
	int		*addr;
	void	*img;
}	t_img_data;

typedef enum e_status
{
	STATUS_OK = 0,
	STATUS_FAIL = 1,
	STATUS_ERROR = 2,
	STATUS_BREAK = 3,
	STATUS_CONTINUE = 4
}	t_status;

typedef enum e_direction
{
	DIR_NORTH = 0,
	DIR_SOUTH = 1,
	DIR_EAST = 2,
	DIR_WEST = 3
}	t_direction;

typedef struct s_minimap
{
	int			size;
	int			offset_x;
	int			offset_y;
	int			view_dist;
	int			tile_size;
	char		**map;
	t_img_data	*image;
}	t_minimap;

typedef struct s_map_data
{
	int			fd;
	int			line_count;
	int			map_height;
	int			map_width;
	int			end_found;
	char		*path;
	char		**file;
}	t_map_data;

typedef struct s_config
{
	int		*floor_color;
	int		*ceiling_color;
	char	*no_text_path;
	char	*so_text_path;
	char	*we_text_path;
	char	*ea_text_path;
}	t_config;

typedef struct s_texture_data
{
	int				size;
	int				x_dir;
	int				y_dir;
	int				config_found;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	double			step;
	double			pos;
	t_config		text_config;
}	t_texture_data;

typedef struct s_movement
{
	int		moved;
	int		move_x;
	int		move_y;
	int		rotate;
	char	direction;
}	t_movement;

// Player structure
typedef struct s_player
{
	double		x_pos;
	double		y_pos;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	t_movement	movement;
}	t_player;

// ray float point direction
typedef struct s_ray_fpoint
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_y;
	double	delta_dist_x;
	double	wall_dist;
	double	wall_x; // need to find usage
}	t_ray_fpoint;

// Raycasting data structure
typedef struct s_ray
{
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	t_ray_fpoint	ray_distance;
}	t_ray;

typedef struct s_game_data
{
	void			*mlx;
	void			*win;
	int				win_height;
	int				win_width;
	int				**texture_pixels;
	int				**textures;
	char			**map;
	t_player		player;
	t_ray			ray;
	t_texture_data	texture_data;
	t_map_data		map_data;
	// t_img_data		mini_map;
}	t_game_data;

// init_data.c
void			ft_initialize_img_data(t_img_data *image);
void			ft_init_ray_fpoint(t_ray_fpoint *ray_fpoint);
void			ft_initialize_ray_data(t_ray *ray);
void			ft_initialize_map_data(t_map_data *map_data);
void			ft_initialize_data(t_game_data *game_data);

// init_mlx.c
void			ft_initialize_image(t_game_data *game_data,
					t_img_data *image, int width, int height);
void			ft_initialize_texture_img(t_game_data *game_data,
					t_img_data *image, char *path);
void			ft_initialize_mlx_screen(t_game_data *game_data);

// init_movement.c
void			ft_initialize_player_direction(t_game_data *game_data);

// init_player.c
void			ft_initialize_player_data(t_player *player);
void			ft_initialize_movemement_direction(t_player *player);

// init_textures.c
void			ft_initialize_graphic_pixels(t_game_data *game_data);
void			ft_get_graphic_location(t_game_data *game_data, t_ray *ray);
void			ft_update_graphic_pixels(t_game_data *game_data,
					t_texture_data *texture, t_ray *ray, int x);
void			ft_initialize_textures(t_game_data *game_data);
void			ft_initialize_textures_data(t_texture_data *textures);

// parsing.c
int				ft_record_lines(t_game_data *game_data, char **file, int i);
int				ft_fill_map_table(t_map_data *map_data,
					char **map_table, int index);
int				ft_get_map_data(t_game_data *game_data, char **file, int i);
void			ft_convert_space_to_wall(t_game_data *game_data);
int				ft_build_map(t_game_data *game_data, char **file, int i);

// check_file.c
bool			ft_comfirm_dir(char *arg);
bool			ft_confirm_cub_file(char *arg);
int				ft_file_and_dir_checker(char *arg, bool cub_file);

// parse_data.c
int				ft_get_total_lines(char *path);
void			ft_fill_table(int row, int column, int i,
					t_game_data *game_data);
void			ft_parse_game_data(char *path, t_game_data *game_data);
int				ft_parse_arguments(t_game_data *game_data, char **argv);
int				ft_exit_game(t_game_data *game_data);

// parse_map.c
char			*ft_get_text_path(char *line, int j);
int				ft_fill_direction(t_texture_data *textures, char *line, int j);
int				ft_handle_space_get_data(t_game_data *game_data,
					char **map, int i, int j);
int				ft_get_gamefiles_data(t_game_data *game_data, char **map);

// validate_map.c
int				ft_validate_horizontal_boundaries(char **map_table, int i,
					int j);
int				ft_validate_map_boundaries(t_map_data *map_data,
					char **map_table);
int				ft_validate_map_components(t_game_data *game_data,
					char **map_table);
int				ft_validate_map_end_reached(t_map_data *map);
int				ft_validate_map(t_game_data *game_data, char **map_table);

// validate_player_position.c
int				ft_validate_position(t_game_data *game_data,
					char **map_table);
int				ft_validate_player_position(t_game_data *game_data,
					char **map_table);
int				ft_handle_player_direction(t_game_data *game_data,
					char current_char);
int				ft_check_player_direction(t_game_data *game_data);
int				ft_find_and_set_player_position(t_game_data *game_data,
					char **map_table);

// validate_textures.c
int				ft_validate_rgb(int *rgb);
unsigned long	ft_con_rgb_hex(int *rgb_tab);
int				ft_validate_textures_map(t_game_data *game_data,
					t_texture_data *textures);

// collision_detection.c
bool			is_valid_wall_position(t_game_data *game_data, double x,
					double y);
bool			is_within_map_bounds(t_game_data *game_data, double x,
					double y);
bool			is_valid_position(t_game_data *game_data, double x,
					double y);
int				ft_validate_movement(t_game_data *game_data, double next_x,
					double next_y);

// event_handler.c
int				ft_handle_key_press(int key_code, t_game_data *game_data);
int				ft_handle_key_release(int key_code, t_game_data *game_data);
void			ft_adjust_mouse_position(t_game_data *game_data, int x, int y);
int				ft_handle_mouse_motion(int x, int y, t_game_data *game_data);
void			ft_setup_input_listeners(t_game_data *game_data);

// player_movement.c
int				ft_move_forward(t_game_data *game_data);
int				ft_move_backward(t_game_data *game_data);
int				ft_move_left(t_game_data *game_data);
int				ft_move_right(t_game_data *game_data);
int				ft_move_player(t_game_data *game_data);

// player_rotation.c
int				ft_rotation(t_game_data *game_data, double rotation_speed);
int				ft_rotate_player(t_game_data *game_data,
					double rotation_direction);

// raycasting.c
void			ft_initialize_raycasting_data(int x, t_ray *ray,
					t_player *player);
void			ft_set_dda(t_ray *ray, t_player *player);
void			ft_perform_dda(t_game_data *game_data, t_ray *ray);
void			ft_calculate_line_height(t_ray *ray, t_game_data *game_data,
					t_player *player);
int				ft_raycasting(t_player *player, t_game_data *game_data);

// render_minimap.c

// render_textures.c
int				*ft_convert_xpm_to_img(t_game_data *game_data, char *path);

// render.c
void			ft_set_frame_image_pixel(t_game_data *game_data,
					t_img_data *image, int x, int y);
void			ft_generate_render_frame(t_game_data *game_data);
void			ft_generate_render_raycast(t_game_data *game_data);
void			ft_generate_render_images(t_game_data *game_data);
int				ft_render(t_game_data *game_data);

// error_handling.c
int				ft_error_msg(char *arg, char *str, int er_code);
int				ft_error_val(int arg, char *str, int er_code);
char			*ft_strtrim_whitespace(const char *str);
int				ft_validate_map_row(t_game_data *game_data, const char *row);

// graphic_utils.c
void			ft_set_image_pixel(t_img_data *image, int x, int y,
					int color_val);
int				*ft_move_to_rgb_contents(char **rgb_to_convert, int *rgb);
int				*ft_compose_rgb_colors(char *line);
int				ft_fill_rgb_color(t_game_data *game_data,
					t_texture_data *textures, char *line, int j);
int				ft_handle_texture_or_color(t_game_data *game_data,
					char **map, int i, int j);

// memory_management.c
void			ft_free_table(void **table);
void			ft_free_texture_data(t_texture_data *textures);
void			ft_free_map_table(t_game_data *game_data);
int				ft_free_game_data(t_game_data *game_data);
void			ft_clean_and_exit(t_game_data *game_data, int exit_code);

// parsing_utils.c
int				ft_empty_char(char c);
size_t			ft_max_width(t_map_data *map_data, int i);
bool			ft_comfirm_digit_absence(char *str);
int				ft_skip_whitespace(char *line, int *index);
int				ft_validate_map_char(t_game_data *game_data, char current_char);

#endif