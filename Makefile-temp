SRCS=./srcs/*.c ./libft/*.c
OBJS=*.o
INCLUDE = includes
ARRCS = ar rcs
LIBS = libft
CCFLAGS = -Wall -Werror -Wextra
CC = gcc
NAME = libftprintf.a

all : ${NAME}

${NAME} : 
	make re -C ${LIBS}
	${CC} ${CCFLAGS} -c ${SRCS} -I ${INCLUDE}
	${ARRCS} ${NAME} ${OBJS}

clean : 
	rm ${OBJS}

fclean : clean
	rm ${NAME}

re : fclean all

.PHONY:	all clean fclean re