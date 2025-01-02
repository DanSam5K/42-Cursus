# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 11:45:32 by dsamuel           #+#    #+#              #
#    Updated: 2025/01/02 18:56:11 by dsamuel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCS_PATH = ./srcs/
OBJS_PATH = ./objs/
INCLUDES = -Iincludes -Ilib/ft_printf/includes -Ilib/libft/includes -Ilib/mlx

# Source files
SRCS_FILES = main.c draw.c errors.c exit_actions.c frees.c \
             game_events_utils.c game_events.c game_init.c map_init_utils.c \
             map_init.c map_validate.c map_utils.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_PATH), $(SRCS_FILES:.c=.o))

# MLX library
MLX_DIR = ./lib/mlx/
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a

# Libraries
LIBFT_DIR = ./lib/libft/
LIBFT = $(LIBFT_DIR)libft.a

FTPRINTF_DIR = ./lib/ft_printf/
FTPRINTF = $(FTPRINTF_DIR)libftprintf.a
LIBS = -L$(MLX_DIR) -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm

# Rules
all: $(NAME)

# Compile the MiniLibX library
$(MLX_LIB):
	@cd $(MLX_DIR) && $(MAKE)
	
# Compile the Libft library
$(LIBFT):
	@cd $(LIBFT_DIR) && $(MAKE)

$(FTPRINTF):
	@cd $(FTPRINTF_DIR) && $(MAKE)

# Create the object directory if it doesn't exist
$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)

# Compile the project
$(NAME): $(MLX_LIB) $(LIBFT) $(FTPRINTF) $(OBJS_PATH) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FTPRINTF) $(MLX_LIB) $(LIBS) -o $(NAME)

# Compile object files
$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean object files
all: $(NAME)

clean:
	@rm -f $(OBJS)
	@cd $(LIBFT_DIR) && $(MAKE) clean
	@cd $(FTPRINTF_DIR) && $(MAKE) clean
	@cd $(MLX_DIR) && $(MAKE) clean

# Full clean (object files + binary + obj folder)
fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFT_DIR) && $(MAKE) fclean
	@cd $(FTPRINTF_DIR) && $(MAKE) fclean
	@cd $(MLX_DIR) && $(MAKE) fclean

# Rebuild the project
re: clean all

.PHONY: all clean fclean re
