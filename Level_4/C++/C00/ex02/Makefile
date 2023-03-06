# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 12:13:04 by pmeising          #+#    #+#              #
#    Updated: 2023/01/23 17:23:27 by pmeising         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= account

C++			:= c++

CFLAGS		:= -Werror -Wextra -Wall -g -std=c++98

RM			:= rm -f

SRCS		:=	./tests.cpp \
				./Account.cpp \
				# ./.cpp \
				# ./Contact.cpp \

OBJS		:= ${SRCS:.c=.o}

all:		$(NAME)

.PHONY:		all clean fclean re

$(NAME):	${OBJS}
			${C++} ${CFLAGS} -o ${NAME} ${SRCS}

re:			fclean all

fclean:
			$(RM) ${NAME}
