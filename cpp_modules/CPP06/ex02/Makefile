# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 16:34:59 by dsamuel           #+#    #+#              #
#    Updated: 2025/04/23 16:36:09 by dsamuel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = base

SRCS = main.cpp Base.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "Compilation complete. Executable: $(NAME)"
	@echo "Run './$(NAME)' to execute the program."
	@echo "Use 'make clean' to remove object files."
	@echo "Use 'make fclean' to remove the executable and object files."

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compiling $< to $@"
	@echo "Object file $@ created."
	@echo "Use 'make' to compile the program."

clean:
	$(RM) $(OBJS)
	@echo "Object files removed."
	
fclean: clean
	$(RM) $(NAME)
	@echo "Executable removed."
	@echo "All files cleaned."

re: fclean all
	@echo "Rebuilding the project."
	@echo "Use 'make' to compile the program."
	@echo "Use 'make clean' to remove object files."
	@echo "Use 'make fclean' to remove the executable and object files."

.PHONY: all clean fclean re