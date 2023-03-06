# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 12:13:04 by pmeising          #+#    #+#              #
#    Updated: 2023/02/01 18:04:51 by pmeising         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= BraiiiiiinZ

SRC 		= 	main.cpp \
				newZombie.cpp \
				randomChump.cpp \
				Zombie.cpp \
				
OBJS 		= 	${SRC:.cpp=.o}

HEADERS		=	Zombie.h Zombie.hpp

FLAGS		=	-Wall -Wextra -Werror -std=c++98

CPP			=	c++

RM 			= 	rm -f

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