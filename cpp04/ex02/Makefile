NAME = fire

CC = c++

CFLAGS = -std=c++98 -Wall -Wextra -Werror

RM = rm -f

SRC = main.cpp \
		AAnimal.cpp \
		Cat.cpp \
		Dog.cpp \
		Brain.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp


INCLUDE = AAnimal.hpp \
			Cat.hpp \
			Dog.hpp \
			Brain.hpp \
			WrongAnimal.hpp \
			WrongCat.hpp \

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
