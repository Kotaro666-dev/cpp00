# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/10 15:08:34 by kkamashi          #+#    #+#              #
#    Updated: 2021/07/23 14:56:14 by kkamashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CXX = clang++
VERSION = -std=c++03
CXXFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = ./megaphone.cpp
OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CXX) $(VERSION) -o $(NAME) $(SRC)

$(OBJ): $(SRC)
	$(CXX) $(VERSION) $(CXXFLAGS) -c $(SRC)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
