# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/16 14:44:29 by dsamuel           #+#    #+#              #
#    Updated: 2024/09/02 11:56:22 by dsamuel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
RM = rm -f
INCLUDE = -Iincludes -Ilib/ft_printf/includes -Ilib/libft/includes
CFLAGS = -Wall -Wextra -Werror

# Source files
ALGO_DIR = algorithm
STACK_DIR = stack
MISC_DIR = misc
BONUS = checker
SRCS_DIR = srcs
MAIN_FILES = main.c $(ALGO_DIR)/push_swap.c
SRCS_FILES = $(ALGO_DIR)/sort_push_swap.c $(ALGO_DIR)/sort_algo_utils.c $(ALGO_DIR)/sort_algo.c $(ALGO_DIR)/calculation.c \
			 $(STACK_DIR)/s_utils.c $(STACK_DIR)/s_operations.c $(STACK_DIR)/s_misc.c $(MISC_DIR)/check.c
SRC_1 = $(addprefix $(SRCS_DIR)/,$(MAIN_FILES))
SRC_2 = $(addprefix $(SRCS_DIR)/,$(SRCS_FILES))
BONUS_SRC = srcs/checker.c srcs/algorithm/push_swap.c

# Object files
OBJ_DIR = obj/
OBJ_1 = ${SRC_1:.c=.o}
OBJ_2 = ${SRC_2:.c=.o}
BONUS_OBJ =${BONUS_SRC:.c=.o}

# Libraries
LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = lib/ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

LIBS = -L$(LIBFT_DIR) -L$(PRINTF_DIR) -lft -lftprintf

# Colors and text formatting
RESET = \033[0m
BOLD = \033[1m
DIM = \033[2m
UNDERLINE = \033[4m
BLINK = \033[5m
INVERT = \033[7m
LIGHT_BLUE = \033[94m
YELLOW = \033[93m

# Makefile rules
# @${CC} -c $(CFLAGS) $(INCLUDE) $< -o ${<:.c=.o}
.c.o:
	@echo "$(BOLD)$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

${NAME}: ${OBJ_1} ${OBJ_2} $(LIBFT) $(PRINTF)
	@echo "$(BOLD)$(LIGHT_BLUE)Linking objects...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) ${OBJ_1} ${OBJ_2} $(LIBS) -o $(NAME)
	@echo "$(BOLD)$(LIGHT_BLUE)$(NAME) created successfully!$(RESET)"
	@echo "$(BOLD)Copyright Reserved. Daniel Samuel(dsamuel)$(RESET)"

${BONUS}: ${OBJ_2} ${BONUS_OBJ} $(LIBFT) $(PRINTF)
	@echo "$(BOLD)$(LIGHT_BLUE)Linking objects...$(RESET)"
	@${CC} ${CFLAGS} ${BONUS_OBJ} ${OBJ_2} $(LIBS) -o ${BONUS} ${INCLUDE}
	@echo "$(BOLD)$(LIGHT_BLUE)$(NAME) created successfully!$(RESET)"
	@echo "$(BOLD)Copyright Reserved. Daniel Samuel(dsamuel).$(RESET)"

$(LIBFT):
	@echo "$(BOLD)$(LIGHT_BLUE)Building libft...$(RESET)"
	@make -C $(LIBFT_DIR) -s

$(PRINTF):
	@echo "$(BOLD)$(LIGHT_BLUE)Building ft_printf...$(RESET)"
	@make -C $(PRINTF_DIR) -s

all: ${NAME}

bonus: ${BONUS} 

clean:
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning objects...$(RESET)"
	@${RM} ${OBJ_1} ${OBJ_2} ${BONUS_OBJ} ${NAME} ${BONUS}
	@make -C $(LIBFT_DIR) clean -s
	@make -C $(PRINTF_DIR) clean -s

fclean: clean
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning $(NAME)...$(RESET)"
	@${RM} ${OBJ_1} ${OBJ_2} ${BONUS_OBJ} ${NAME} ${BONUS}
	@make -C $(LIBFT_DIR) fclean -s
	@make -C $(PRINTF_DIR) fclean -s

re: clean all

.PHONY: all bonus clean fclean re bonus