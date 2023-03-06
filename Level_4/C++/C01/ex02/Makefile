# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 12:13:04 by pmeising          #+#    #+#              #
#    Updated: 2023/02/01 17:53:55 by pmeising         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= HI_THIS_IS_BRIAN

SRC 		= 	main.cpp \
				
OBJS 		= 	${SRC:.cpp=.o}

FLAGS		=	-Wall -Wextra -Werror -std=c++98

CPP			=	c++

RM 			= 	rm -f

%.o:			%.cpp
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