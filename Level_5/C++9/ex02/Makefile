NAME		:=	PmergeMe

SRC 		:=	main.cpp PmergeMe.cpp \

TESTING		:=	tests.cpp PmergeMe.cpp \

T_OBJS		:=	${TESTING:.cpp=.o}
				
OBJS 		:= 	${SRC:.cpp=.o}

HEADERS		:=	PmergeMe.hpp

FLAGS		:=	-Wall -Wextra -Werror -std=c++98

CPP			:=	c++

RM 			:= 	rm -f

%.o:			%.cpp ${HEADERS}
				${CPP} -c ${FLAGS} -I. $< -o ${<:.cpp=.o}

${NAME}:		${OBJS}
				${CPP} ${FLAGS} ${OBJS} -o ${NAME}

all:			${NAME}

testing:		${T_OBJS}
				${CPP} ${FLAGS} ${T_OBJS} -o ${NAME}

clean:
				${RM} ${OBJS} ${T_OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re

