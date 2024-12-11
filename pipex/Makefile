# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/17 14:17:59 by dsamuel           #+#    #+#              #
#    Updated: 2024/09/19 11:42:33 by dsamuel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program names
PROG	= pipex
PROG_B	= pipex_bonus

# Source files for main program
SRCS	= srcs/pipex.c srcs/pipex_utils.c
OBJS	= $(SRCS:.c=.o)
MAIN	= srcs/pipex.c
LIB 	= libft/libft.a

# Source files for bonus program
SRCS_B 	= srcs/pipex_bonus.c srcs/pipex_utils_bonus.c srcs/pipex_utils.c
OBJS_B	= $(SRCS_B:.c=.o)
MAIN_B	= srcs/pipex_bonus.c

# Header directories
HEADER	= -Iincludes -Ilibft/includes

# Compiler and flags
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

# Compilation rule for object files
.c.o:
		$(CC) $(CFLAGS) $(HEADER) -c $< -o $(<:.c=.o)
		
# Default target: build the main program
all:	$(PROG)

# Build libft
$(LIB):
		make -C libft

# Link main program
$(PROG): $(OBJS) $(LIB)
		$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(PROG)

# Target for compiling the bonus section only
bonus:	$(PROG_B)

# Link bonus program
$(PROG_B): $(OBJS_B) $(LIB)
		$(CC) $(CFLAGS) $(OBJS_B) $(LIB) -o $(PROG_B)

# Clean main program object files
clean_main:
		rm -f $(OBJS)
		make clean -C libft

# Clean bonus program object files
clean_bonus:
		rm -f $(OBJS_B)

# Clean both main and bonus object files
clean: clean_main clean_bonus

# Full clean for main program (objects and executable)
fclean_main: clean_main
		rm -f $(PROG)
		make fclean -C libft

# Full clean for bonus program (objects and executable)
fclean_bonus: clean_bonus
		rm -f $(PROG_B)

# Full clean for both main and bonus programs
fclean: fclean_main fclean_bonus

# Rebuild main program
re_main: fclean_main all

# Rebuild bonus program
re_bonus: fclean_bonus bonus

# Rebuild both main and bonus programs
re: fclean all bonus

# Declare phony targets to prevent conflicts with file names
.PHONY: all clean clean_main clean_bonus fclean fclean_main fclean_bonus re re_main re_bonus bonus
