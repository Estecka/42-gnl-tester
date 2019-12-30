SRCS = $(wildcard *.c) ../get_next_line.c ../get_next_line_utils.c
OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra

NAME = test.out

${NAME}: ${OBJS}

autorun: ${NAME}

all: ${name}

clean:
	rm -f *.o ../*.o
	rm -f *.gch ../*.gch

fclean: clean
	rm -f ${name}

re: fclean all

.PHONY: all clean fclean re
