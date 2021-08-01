# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/23 11:49:44 by kkamashi          #+#    #+#              #
#    Updated: 2021/07/24 17:21:03 by kkamashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tests

CXX = clang++
VERSION = -std=c++03
CXXFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS =	./tests.cpp \
		./Account.cpp

OBJS = $(SRCS:.cpp=.o)

LOG_FILE = ./output.log

$(NAME): $(OBJS)
	$(CXX) $(VERSION) -o $(NAME) $(SRCS)

$(OBJS): $(SRCS)
	$(CXX) $(VERSION) $(CXXFLAGS) -c $(SRCS)

all: $(NAME)

output:
	./${NAME} > ${LOG_FILE}

diff:
	diff sample.log ${LOG_FILE}

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) ${LOG_FILE}

re: fclean all

.PHONY: all clean fclean re
