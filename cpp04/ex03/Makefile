NAME = recap

CC = c++

CFLAGS = -fsanitize=address -g3 -pedantic -std=c++98 -Wall -Wextra #-Werror

RM = rm -f

SRC = main.cpp \
	  AMateria.cpp \
	  Cure.cpp \
	  Ice.cpp \
	  Character.cpp

INCLUDE = AMateria.hpp \
		  Cure.hpp \
		  Ice.hpp \
		  ICharacter.hpp \
		  Character.hpp

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
