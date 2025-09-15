NAME = ex02

C++ = c++
C++FLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -pedantic
SRC = main.cpp\
	Bureaucrat.cpp\
	AForm.cpp\
	ShrubberyCreationForm.cpp\
	RobotomyRequestForm.cpp\
	PresidentialPardonForm.cpp

OBJ = $(SRC:.cpp=.o)
D = $(OBJ:.o=.d)
all: $(NAME)

$(NAME): $(OBJ)
	$(C++) $(C++FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(C++) $(C++FLAGS) -c $< -o $@

clean:
	-rm -f $(OBJ) $(D)

fclean: clean
	-rm -f $(NAME)

re: fclean all

-include $(D)

.PHONY: all clean fclean re
