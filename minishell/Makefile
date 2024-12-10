# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 19:43:40 by dsamuel           #+#    #+#              #
#    Updated: 2024/12/10 11:02:08 by dsamuel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I include/ -I libft/includes/

LIBFT = -L libft -lft

LIBS = -lreadline -lhistory

HEADER = minishell.h

BUILTINS = cd echo env exit export pwd unset

ENV = env_vars get_env shell_val_level sort_env

HISTORY = history

EXECUTOR = command executor builtin

MAIN = minishell redirections

PARSER = parser_line expansions tokenizer here_doc

UTILS = expansion free fd parsing token type execute here_doc_util

SIGNALS = signals

SRC = $(addsuffix .c, $(addprefix src/builtins/, $(BUILTINS))) \
	  $(addsuffix .c, $(addprefix src/env/, $(ENV))) \
	  $(addsuffix .c, $(addprefix src/executor/, $(EXECUTOR))) \
	  $(addsuffix .c, $(addprefix src/main/, $(MAIN))) \
	  $(addsuffix .c, $(addprefix src/parser/, $(PARSER))) \
	  $(addsuffix .c, $(addprefix src/utils/, $(UTILS))) \
	  $(addsuffix .c, $(addprefix src/signals/, $(SIGNALS))) \
	  $(addsuffix .c, $(addprefix src/history/, $(HISTORY))) \

OBJ = $(SRC:c=o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n"
	@make -C libft/
	@echo "\033[0;32mCompiling minishell..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LIBS)
	@echo "\n\033[0mDone !"

%.o: %.c
	@printf "\033[0;33mGenerating minishell objects... %-33.33s\r" $@
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@echo "\033[0;31mCleaning libft..."
	@make clean -C libft/
	@echo "\nRemoving binaries..."
	@rm -f $(OBJ)
	@echo "\033[0m"

fclean:
	@echo "\033[0;31mCleaning libft..."
	@make fclean -C libft/
	@echo "\nDeleting objects..."
	@rm -f $(OBJ)
	@echo "\nDeleting executable..."
	@rm -f $(NAME)
	@echo "\033[0m"

re: fclean all

test: all
	./minishell

leak: re
	valgrind --leak-check=full ./minishell

.PHONY: clean fclean re test norm