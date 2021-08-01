# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/10 16:05:17 by kkamashi          #+#    #+#              #
#    Updated: 2021/07/23 14:51:16 by kkamashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CXX = clang++
VERSION = -std=c++03
CXXFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS =	./main.cpp \
		./PhonebookClass.cpp \
		./ContactClass.cpp
OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CXX) $(VERSION) -o $(NAME) $(SRCS)

$(OBJS): $(SRCS)
	$(CXX) $(VERSION) $(CXXFLAGS) -c $(SRCS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
