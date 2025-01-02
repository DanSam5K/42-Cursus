/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:26:53 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/13 20:08:14 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/mlx/mlx.h"
# include "../lib/libft/includes/libft.h"
# include "../lib/ft_printf/includes/ft_printf.h"

# include "custom_letters.h"
# include <fcntl.h>
# include <string.h>

// GAME OBJECTS KEYS
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define WALL '1'
# define EMPTY '0'

// GAME KEYWORDS
# define ESC 65307
# define W 119
# define UP 65362
# define A 97
# define LEFT 65361
# define S 115
# define DOWN 65364
# define D 100
# define RIGHT 65363
# define RESTART 114

# define MAX_FILES 1

# define TRUE 1
# define FALSE 0

# define CELL_SIZE 64

// OBJECTS : IMAGES
typedef struct s_game_objs
{
	void	*player;
	void	*player_left;
	void	*player_right;
	void	*player_down;
	void	*player_up;
	void	*collectible;
	void	*exit_open;
	void	*exit_close;
	void	*wall;
	void	*floor;
	int		img_width;
	int		img_height;
}	t_game_objs;

// POSITIONS OF PLAYER AND EXIT
typedef struct s_game_pos
{
	int	player_row;
	int	player_col;
	int	exit_row;
	int	exit_col;
}	t_game_pos;

// GAME DATA OF THE OBJECTS INSIDE THE matrix (INTERNAL)
typedef struct s_game_data
{
	int	count_player;
	int	count_exit;
	int	count_collectible;
	int	count_wall;
	int	count_empty;
	int	count_movements;
	int	endgame;
}	t_game_data;

// GAME RESOLUTIONS 
typedef struct s_game_resolutions
{
	int		set_map_width;
	int		set_map_height;
	char	*set_name_window;
	char	*set_name_map;
}	t_game_res;

// GAME DATA OF matrix (EXTERN)
typedef struct s_map_data
{
	int					first_read_matrix;
	int					cols_matrix;
	int					rows_matrix;
	int					size_matrix;
	char				**matrix;
	t_game_res			resolutions;
	t_game_pos			pos;
}	t_map_data;

// MAIN GAME CONTROLLER
typedef struct s_game_instance
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					argc_tmp;
	char				**argv_tmp;
	t_map_data			map_init;
	t_game_pos			pos_init;
	t_game_data			game_data;
	t_game_res			res_init;
	t_game_objs			game_objs;
}	t_game_instance;

/* ------- STARTS HERE INITIALIZE AND SET GAME PROPS -------*/
int			main(int argc, char **argv);
void		ft_struct_init(t_game_instance *game_init);
void		ft_initialize_game(t_game_instance *game_init);

/* --------- GAME EVENTS AND ACTIONS + GRAPHICS --------- */
int			ft_check_keyboard(int key, t_game_instance *game_init);
int			ft_non_special(int key, t_game_instance *game_init);
int			ft_exit_program(t_game_instance *game_init);
void		ft_reset_game(t_game_instance *game_init);

/* --------- MAP VALIDATIONS AND MAP DATA --------- */
int			ft_open_map(char *map, t_game_instance *game_init);
int			ft_read_count_map(char *map);
int			ft_count_lines(int fd);
int			ft_map_dimensions(t_game_instance *game_init);
int			get_rows_count(t_game_instance *game_init);
int			get_cols_count(t_map_data *map_init);
int			ft_read_map(int fd, t_game_instance *game_init);
int			ft_check_read(t_game_instance *game_init);
int			ft_map_extension(char *map);
int			ft_is_valid_map(t_game_instance *game_init);
int			ft_is_map_shape_valid(t_game_instance *game_init);
int			ft_is_wall(t_game_instance *game_init);
int			ft_count_map_objects(t_game_instance *game_init);
int			ft_have_requires(t_game_instance *game_init);

/*------ GAME EVENTS AND ACTIONS + GRAPHICS ------*/
void		ft_start_game(t_game_instance *game_init);
int			ft_events_pressed(t_game_instance *game_init, int column, int row);
void		ft_win(t_game_instance *game_init);
int			ft_print_shell(t_game_instance *game_init);
int			ft_exit_program(t_game_instance *game_init);
void		ft_reset_game(t_game_instance *game_init);
void		ft_locate_player(t_game_instance *game_init);

/* --------- GAME OBJECTS AND GRAPHICS CHECKS AND DRAW --------- */
void		ft_img_init(t_game_instance *game_init);
void		ft_check_img(t_game_instance *game_init, void **image, char *path);
int			ft_map_draw(t_game_instance *game_init);
void		ft_map_continues(t_game_instance *game_init, int column, int row);
void		ft_set(t_game_instance *game_init, void *img, int wid, int hgt);

/* --------- FREE MEMORY AND CLEANUP ------------- */
void		ft_free_map(t_game_instance *game_init);
void		ft_free_img(t_game_instance *game_init);
void		ft_cleanup(t_game_instance *game_init);

/*----- CUSTOM LETTERS AND ERRORS ------*/
void		ft_error_init(int n);
void		ft_error_map(int n);

/*--------- AUXILIARY FUNCTIONS ---------*/
int			ft_strcmp(const char *s1, const char *s2);
char		*get_next_line(int fd);

int			ft_check_path(t_game_instance *game, int **marked);
int			ft_has_path(t_game_instance *game);
void		ft_mark_path(t_game_instance *game,
				int row, int col, int **marked);
void		ft_find_player(t_game_instance *game,
				int *start_row, int *start_col);

#endif
