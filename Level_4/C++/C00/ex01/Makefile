# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 12:13:04 by pmeising          #+#    #+#              #
#    Updated: 2023/01/25 18:16:25 by pmeising         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= phonebook

C++			:= c++

CFLAGS		:= -Werror -Wextra -Wall -g -std=c++98

RM			:= rm -f

SRCS		:=	./main.cpp \
				./PhoneBook.cpp \
				./Contact.cpp \

OBJS		:= ${SRCS:.cpp=.o}

all:		$(NAME)

.PHONY:		all clean fclean re

$(NAME):	${OBJS}
			${C++} ${CFLAGS} -o ${NAME} ${SRCS}

re:			fclean all

fclean:
			$(RM) phonebook
