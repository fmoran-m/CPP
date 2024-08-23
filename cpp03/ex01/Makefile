NAME = scavtrap

CC = c++

CFLAGS = -std=c++98 -Wall -Wextra -Werror

RM = rm -f

SRC = main.cpp \
	  ClapTrap.cpp \
	  ScavTrap.cpp

INCLUDE = ClapTrap.hpp \
			ScavTrap.hpp

OBJS = ${SRC:.cpp=.o}

$(NAME): $(OBJS) $(INCLUDE)
			$(CC) -o $(NAME) $(CFLAGS) $(OBJS)

all: $(NAME)

%.o:%.cpp
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY = all clean fclean re
