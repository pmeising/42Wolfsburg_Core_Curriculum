NAME		:= FragTrap

SRC 		:=	main.cpp \
				ClapTrap.cpp \
				ScavTrap.cpp \
				FragTrap.cpp \
				
OBJS 		:= 	${SRC:.cpp=.o}

HEADERS		:=	ClapTrap.hpp ScavTrap.hpp FragTrap.hpp

FLAGS		:=	-Wall -Wextra -Werror -std=c++98

CPP			:=	c++

RM 			:= 	rm -f

%.o:			%.cpp ${HEADERS}
				${CPP} -c ${FLAGS} -I. $< -o ${<:.cpp=.o}

${NAME}:		${OBJS}
				${CPP} ${FLAGS} ${OBJS} -o ${NAME}

all:			${NAME}

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re