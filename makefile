SRCS = $(wildcard *.c ../*.c)
OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra

NAME = test.out

TESTC = 2

${NAME}: ${OBJS}
	gcc ${OBJS} -o ${NAME}

autorun: fclean ${NAME}
	./${NAME} ${TESTC}

all: ${name}

clean:
	rm -f *.o ../*.o
	rm -f *.gch ../*.gch

fclean: clean
	rm -f ${name}

re: fclean all

.PHONY: all clean fclean re
