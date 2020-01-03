/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 14:54:44 by abaur             #+#    #+#             */
/*   Updated: 2020/01/03 11:00:47 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "logutil/logutil.h"
int	get_next_line(int, char**);

void TestOneGNL(){
	char* line = NULL;
	int r;

	r = get_next_line(0, &line);

	if (r == 1) {
		printf("%s\n", line);
		for (line; *line; line++){
			if (*line == '\n' || *line == EOF || *line == 0)
				printfc(YELLOW, 1, "%02X ", *line);
			else
				printf ("%02X ", *line);
		}
		printf("\n");
	}
	else
		printf("Unexpected return value: %d\n", r);
}

int	main(int argc, char **args){
	int count;
	
	count = atoi(args[1]);
	if (count < 1)
		count = 1;

	for (int i=0; i<count; i++){
		TestOneGNL();
	}
}
