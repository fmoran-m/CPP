# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/22 13:50:01 by fmoran-m          #+#    #+#              #
#    Updated: 2024/11/22 14:18:12 by fmoran-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

CC = c++

CFLAGS = -std=c++98 -Wall -Wextra -Werror

RM = rm -f

SRC = main.cpp \
	  RPN.cpp

INCLUDE = RPN.hpp

OBJS = ${SRC:.cpp=.o}

$(NAME): $(OBJS) $(INCLUDE)
			$(CC) -o $(NAME) $(CFLAGS) $(OBJS)

all: $(NAME)

%.o:%.cpp $(INCLUDE)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY = all clean fclean re
