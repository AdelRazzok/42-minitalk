# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlaval <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 13:34:05 by mlaval            #+#    #+#              #
#    Updated: 2023/05/05 14:24:50 by mlaval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_NAME = client

S_NAME = server

C_SRC = client.c ./utils/utils.c ./utils/ft_printf.c ./utils/ft_printf_utils.c

S_SRC = server.c ./utils/utils.c ./utils/ft_printf.c ./utils/ft_printf_utils.c

CC = gcc

CFLAGS = -Wall -Werror -Wextra

C_OBJ = ${C_SRC:.c=.o}

S_OBJ = ${S_SRC:.c=.o}

all : ${C_NAME} ${S_NAME}

${C_NAME} : ${C_OBJ}
			${CC} ${CFLAGS} -o ${C_NAME} ${C_OBJ}

${S_NAME} : ${S_OBJ}
			${CC} ${CFLAGS} -o ${S_NAME} ${S_OBJ}

clean : 
		rm -rf ${C_OBJ} ${S_OBJ}

fclean : clean
		rm -rf ${C_NAME} ${S_NAME}

re : fclean all