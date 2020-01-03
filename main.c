/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 14:54:44 by abaur             #+#    #+#             */
/*   Updated: 2020/01/03 11:47:41 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

#include "logutil/logutil.h"
int	get_next_line(int, char**);

int TestOneGNL(int fd){
	char* line = NULL;
	int err;

	err = get_next_line(fd, &line);

	if (-1 < err) {
		printf("%s\n", line);
		for (line; *line; line++){
			if (*line == '\n' || *line == EOF || *line == 0)
				printfc(CYAN, 1, "%02X ", *line);
			else
				printf ("%02X ", *line);
		}
		printf("\n");
	}
	else
		printf("Unexpected return value: %d\n", err);

	return err;
}

int	main(int argc, char **args){
	int fd = 0;

	if (argc > 1)
		fd = open(args[1], O_RDONLY);
	if (fd < 0){
		printfc(YELLOW, 1, "Error opening file: %#x", errno);
		return -1;
	}

	while(0 < TestOneGNL(fd));

}
