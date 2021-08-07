SRCS = *.c
OBJS= ${SRCS:.c=.o}
BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c
BONUS_OBJS = ${BONUS_SRCS:.c=.o}
INCLUDE = libft.h
ARRCS = ar rcs
RANLIB = ranlib
CCFLAGS = -Wall -Werror -Wextra
CC = gcc
NAME = libft.a

all : ${NAME}
		make clean

bonus : ${NAME} ${BONUS_OBJS}
	${ARRCS} ${NAME} ${BONUS_OBJS}
	${RANLIB} ${NAME}


$(NAME) : ${OBJS} ${INCLUDE}
	${ARRCS} ${NAME} ${OBJS}
	${RANLIB} ${NAME}

.c.o :
	${CC} ${CCFLAGS} -I . -c $< -o ${<:.c=.o}

clean :
	rm -f ${OBJS} ${BONUS_OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

rebonus : fclean bonus
