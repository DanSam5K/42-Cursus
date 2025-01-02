# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 14:10:15 by dsamuel           #+#    #+#              #
#    Updated: 2025/01/02 18:55:27 by dsamuel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I includes -I libft/includes
SOURCES = ft_flags_utils.c ft_flags.c ft_num_len.c ft_printchar.c ft_printf_itoa.c \
		  ft_printf_utoa.c ft_printf_xtoa.c ft_printf.c ft_printhex.c ft_printint.c \
		  ft_printptr.c ft_printstr.c ft_printunsigned.c
SRC = $(addprefix src/, $(SOURCES))
OBJS = ${SRC:.c=.o}
RM = rm -rf

${NAME} : ${OBJS}
	@cd libft && $(MAKE)
	@cp libft/libft.a $(NAME)
	@ar -rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	@cd libft && $(MAKE) clean
	@$(RM) $(OBJS)

fclean: clean
	@cd libft && $(MAKE) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
