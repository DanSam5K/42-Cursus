# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 18:55:23 by dsamuel           #+#    #+#              #
#    Updated: 2025/01/07 18:55:26 by dsamuel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp\

OBJS = $(SRCS:.cpp=.o)
NAME = a.out
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++
RM = rm -f

ifdef DEBUG
	CXXFLAGS += -g -fsanitize=address
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

debug:
	$(CXX) -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address  -o $(NAME) $(SRCS)

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
