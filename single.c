/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:37:03 by abaur             #+#    #+#             */
/*   Updated: 2020/01/13 14:16:44 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testutil.h"

/*
** Calls GNL once on the given file and prints the result.
** @return The return value of GNL.
*/
static int TestOneGNL(int fd){
	char* line = NULL;
	int err;

	err = get_next_line(fd, &line);
	char* cursor = line;

	printf("|");
	if (-1 < err)
		while (printline_row(cursor)){
			printf(" ");
			cursor += COLCOUNT;
		}
	else
		printfc(MAGENTA, 1, "Unexpected return value: %d\n", err);

	if (line)
		free(line);

	return err;
}

/*
** Runs GNL on a single file until the end.
** @param char* path The path to the file, or NULL to test the standard entry.
** @return 0 if the test was performed throughout. An error code if the file could not be opened.
*/
int TestOneFile(char* path){
	int fd = 0;
	if (path)
		fd = open(path, O_RDONLY);
	if (fd < 0){
		printfc(YELLOW, 1, "Error opening file: %#x\n", errno);
		return errno;
	}

	while(0 < TestOneGNL(fd));

	return 0;
}
