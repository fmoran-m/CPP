NAME = poly

CC = c++

CFLAGS = -fsanitize=address -std=c++98 -Wall -Wextra -Werror

RM = rm -f

SRC = main.cpp \
		Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		Brain.cpp

INCLUDE = Animal.hpp \
			Cat.hpp \
			Dog.hpp \
			Brain.hpp


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
