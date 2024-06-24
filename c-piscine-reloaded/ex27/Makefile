# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/06 20:01:35 by dsamuel           #+#    #+#              #
#    Updated: 2024/06/07 20:09:47 by dsamuel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.c

OBJS		:= $(SRCS:.c=.o)

CC			= cc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -I. -o $(NAME)

NAME		= ft_display_file

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

.PHONY:		all clean fclean
