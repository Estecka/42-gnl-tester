/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 14:54:44 by abaur             #+#    #+#             */
/*   Updated: 2020/01/03 16:29:56 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <ctype.h>

#include "logutil/logutil.h"
int	get_next_line(int, char**);

#define COLCOUNT 42

/*
* Returns false if the end of line was reached.
*/
static short printline_row(const char* line, short isEOF){
	char lastChar = 0;
	(void)isEOF;
	int i;

	if (!line){
		printfc(RED, 1, "%-*.*s", COLCOUNT, COLCOUNT, NULL);
		printf("\n");
		return 0;
	}

	for(i=0; i<COLCOUNT; i++){
		if (line[i]){
			lastChar = line[i];
			if (line[i] == '\n')
				printfc(RED, 1, "$");
			else if (isspace(line[i]))
				printf(" ");
			else
				printf("%c", line[i]);
		} else {
			printf("%-*c", COLCOUNT-i, ' ');
			break;
		}
	}

	for (i=0; i<COLCOUNT; i++){
		if (line[i])
			printfc(line[i]=='\n' ? RED : CLEAR, 0, "%.*c%02X", i>0, ' ', line[i]);
		else {
			printf("%-*c", COLCOUNT-i, ' ');
			printf("\n");
			return 0;
		}
	}

	printf("\n");
	return line[i] != 0;
}

int TestOneGNL(int fd){
	char* line = NULL;
	int err;

	err = get_next_line(fd, &line);

	printf("|");
	if (-1 < err)
		while (printline_row(line, err == 0)){
			printf(" ");
			line += COLCOUNT;
		}
	else
		printfc(MAGENTA, 1, "Unexpected return value: %d\n", err);

	return err;
}

int	main(int argc, char **args){
	int fd = 0;

	if (argc > 1)
		fd = open(args[1], O_RDONLY);
	if (fd < 0){
		printfc(YELLOW, 1, "Error opening file: %#x\n", errno);
		return errno;
	}

	while(0 < TestOneGNL(fd));

}
