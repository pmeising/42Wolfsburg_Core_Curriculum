NAME		:=	Intern

SRC 		:=	main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp Intern.cpp \
				
				
OBJS 		:= 	${SRC:.cpp=.o}

HEADERS		:=	Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp Intern.hpp

FLAGS		:=	-Wall -Wextra -Werror -std=c++98

CPP			:=	c++

RM 			:= 	rm -f

%.o:			%.cpp ${HEADERS}
				${CPP} -c ${FLAGS} -I. $< -o ${<:.cpp=.o}

${NAME}:		${OBJS}
				${CPP} ${FLAGS} ${OBJS} -o ${NAME}

all:			${NAME}

clean:
				${RM} ${OBJS} test_shrubbery

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re