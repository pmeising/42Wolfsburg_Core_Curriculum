NAME		:=	Thoughts

SRC 		:=	main.cpp \
				aAnimal.cpp \
				Cat.cpp \
				Dog.cpp \
				Brain.cpp \
				WrongAnimal.cpp \
				WrongCat.cpp \
				WrongDog.cpp \
				
OBJS 		:= 	${SRC:.cpp=.o}

HEADERS		:=	aAnimal.hpp Cat.hpp Dog.hpp Brain.hpp WrongAnimal.hpp WrongCat.hpp WrongDog.hpp

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