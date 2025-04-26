# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/20 15:02:36 by dsamuel           #+#    #+#              #
#    Updated: 2025/04/09 20:50:23 by dsamuel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Project name
NAME	= cub3D

CC		= cc
CFLAGS	= -Werror -Wextra -Wall -g3 #-fsanitize=address

# minilibx-linux and libft libraries
MLX_PATH	= lib/minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

LIBFT_PATH	= lib/libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

# src files
SRC_PATH = ./src/
SRC		= 	cub3dgame/main.c \
            initialization/init_data.c initialization/init_mlx.c initialization/init_textures.c initialization/init_movement.c \
            initialization/init_player.c parsing/build_map.c parsing/check_file.c parsing/parse_data.c parsing/parse_map.c parsing/validate_map.c \
            parsing/validate_player_position.c parsing/validate_textures.c player/collision_detection.c player/player_movement.c player/player_rotation.c \
            player/event_handler.c rendering/raycasting.c rendering/render_textures.c rendering/render.c \
            utils/error_handling.c utils/graphic_utils.c utils/memory_management.c utils/parsing_utils.c

SRCS	= $(addprefix $(SRC_PATH), $(SRC))

# obj files
OBJ_PATH	= ./objects/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

# Includes
INC			=	-I ./includes/\
                -I ./lib/libft/\
                -I ./lib/minilibx-linux/

# Main rule
all: $(OBJ_PATH) $(MLX) $(LIBFT) $(NAME)

# Clone minilibx-linux repository if it doesn't exist
$(MLX_PATH):
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_PATH)
	git submodule update --init --recursive

# Objects directory rule
$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)
	mkdir -p $(OBJ_PATH)/cub3dgame
	mkdir -p $(OBJ_PATH)/debugtools
	mkdir -p $(OBJ_PATH)/initialization
	mkdir -p $(OBJ_PATH)/parsing
	mkdir -p $(OBJ_PATH)/player
	mkdir -p $(OBJ_PATH)/rendering
	mkdir -p $(OBJ_PATH)/utils

# Objects rule
$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

# Project file rule
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC) $(LIBFT) $(MLX) -lXext -lX11 -lm

$(LIBFT):
	make -sC $(LIBFT_PATH)

$(MLX): $(MLX_PATH)
	make -sC $(MLX_PATH)

clean:
	rm -rf $(OBJ_PATH)
	make -C $(LIBFT_PATH) clean
	@if [ -d "$(MLX_PATH)" ]; then \
		make -C $(MLX_PATH) clean; \
	fi
    
fclean: clean
	rm -f $(NAME)
	rm -rf $(MLX_PATH)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all re clean fclean bonus
