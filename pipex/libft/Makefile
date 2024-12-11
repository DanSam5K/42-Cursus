# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 12:03:53 by dsamuel           #+#    #+#              #
#    Updated: 2024/09/09 16:46:09 by dsamuel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR = src/
SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_strlen.c ft_strchr.c \
		  ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		  ft_toupper.c ft_tolower.c ft_memchr.c ft_isprint.c ft_strrchr.c ft_strncmp.c \
		  ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		  ft_itoa.c ft_strmapi.c ft_striteri.c ft_strtrim.c ft_split.c ft_putchar_fd.c \
		  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRCS_B = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
		  ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
		  ft_lstmap_bonus.c get_next_line.c

CFILES	= $(addprefix $(SRCS_DIR), $(SRCS))
CFILES_B = $(addprefix $(SRCS_DIR), $(SRCS_B))
		  
OBJS	= $(CFILES:.c=.o)
OBJS_B	= $(CFILES_B:.c=.o)
INCS	= ./includes
NAME	= libft.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I$(INCS)
AR      = ar
ARFLAGS = -rcs
RM		= rm -f

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_B)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(OBJS_B)

bonus: $(OBJS) $(OBJS_B)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(OBJS_B)

%.o: %.c $(INCS)
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus

