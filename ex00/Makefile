NAME = ex00

C++ = c++
C++FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(C++) $(C++FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(C++) $(C++FLAGS) -c $< -o $@

clean:
	-rm -f $(OBJ)

fclean: clean
	-rm -f $(NAME)

re: fclean, all

PHONY: all, clean, fclean, re