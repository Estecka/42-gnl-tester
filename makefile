SRCS = $(wildcard *.c ../*.c)
OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra

NAME = test.out

${NAME}: ${OBJS}
	gcc ${OBJS} -o ${NAME}

autorun: fclean ${NAME}
	./${NAME} 5

all: ${name}

clean:
	rm -f *.o ../*.o
	rm -f *.gch ../*.gch

fclean: clean
	rm -f ${name}

re: fclean all

.PHONY: all clean fclean re
