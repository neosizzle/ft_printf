SRCS=./srcs/*.c ./libft/*.c
OBJS=*.o
INCLUDE = includes
ARRCS = ar rcs
LIBS = libft
CCFLAGS = -Wall -Werror -Wextra -fsanitize=address
CC = gcc
NAME = libftprintf

all : ${NAME}

${NAME} : 
	make re -C ${LIBS}
	${CC} ${CCFLAGS} ${SRCS} -I ${INCLUDE}

clean : 
	rm ${OBJS}

fclean : clean
	rm ${NAME}

re : fclean all

.PHONY:	all clean fclean re