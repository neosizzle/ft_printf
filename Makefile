SRCS=srcs/*.c cases/*.c utils/*.c
OBJS=*.o
INCLUDE = includes
ARRCS = ar rcs
LIBFT = libft
CCFLAGS = -Wall -Werror -Wextra
CC = gcc
NAME = libftprintf.a

all : ${NAME}

bonus : ${NAME}

${NAME} : 
	make re -C ${LIBFT}
	${CC} ${CCFLAGS} -c ${SRCS}  -I ${INCLUDE}
	${ARRCS} ${NAME} ${OBJS} ${LIBFT}/*.o

clean : 
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY:	all clean fclean re