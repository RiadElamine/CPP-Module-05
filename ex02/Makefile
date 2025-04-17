NAME = Bureaucrat

SOURCE = Bureaucrat.cpp main.cpp AForm.cpp \
	 PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp

OBJECT = $(SOURCE:.cpp=.o)

HEARDER = Bureaucrat.hpp AForm.hpp \
	 PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp

CFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJECT)
	c++ $(CFLAGS) $(OBJECT) -o $(NAME)

%.o: %.cpp $(HEARDER)
	c++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all