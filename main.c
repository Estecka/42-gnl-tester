/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 14:54:44 by abaur             #+#    #+#             */
/*   Updated: 2020/01/14 14:00:14 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testutil.h"

/*
** Prints up to COLCOUNT characters from the given string.
** @return
** 	false The string was fully printed.
** 	true  The string was partially printed.
*/
short printline_row(const char* line){
	char lastChar = 0;
	int i;

	if (!line){
		printfc(RED, 1, "%-*.*s", COLCOUNT, COLCOUNT, NULL);
		printf("\n");
		return 0;
	}

	// Prints the characters
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

	// Prints their hex values
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

int	main(int argc, char **args){
	if (argc <= 1) {
		TestOneFd(0);
		return 0;
	}
	else if (argc == 2) {
		TestOneArg(args[1]);
		if (errno)
			printfc(YELLOW, 1, "Error opening \'%s\' : %#d\n", args[1], errno);
		else
			return 0;
	}
	else {
		int i = TestWovenArgs(argc-1, args+1);
		if (errno) {
			printfc(YELLOW, 1, "Error opening \'%s\' : %#d\n", args[i+1], errno);
			return errno;
		}
	}
}
