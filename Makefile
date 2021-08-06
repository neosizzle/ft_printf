SRCS=./srcs/*.c ./libft/*.c
OBJS=*.o
INCLUDE = includes
ARRCS = ar rcs
LIBS = libft
CCFLAGS = -Wall -Werror -Wextra
CC = gcc
NAME = libftprintf.a

all : ${NAME}

bonus : ${NAME}

${NAME} : 
	make re -C ${LIBS}
	${CC} ${CCFLAGS} -c ${SRCS} -I ${INCLUDE}
	${ARRCS} ${NAME} ${OBJS}

clean : 
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY:	all clean fclean re