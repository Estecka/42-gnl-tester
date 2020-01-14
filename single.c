/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:37:03 by abaur             #+#    #+#             */
/*   Updated: 2020/01/14 12:11:28 by abaur            ###   ########.fr       */
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
		printfc(MAGENTA, 1, "Returned: %d\n", err);

	if (line)
		free(line);

	return err;
}

/*
** Runs GNL on an arbitrary file descriptor until the end.
** @param int fd The file descriptor to read from.
*/
inline void TestOneFd(int fd) {
	while (0 < TestOneGNL(fd));

	if (errno == 9)
		errno = 0;
}

/*
** Runs GNL on a single file until the end.
** @param char* path The path to the file.
** @return 0 if the test was performed throughout. An error code if the file could not be opened.
*/
int TestOneFile(char* path){
	int fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return errno;

	TestOneFd(fd);
	return 0;
}

/*
** Determines whether the argument is a file descriptor or a file path, and tests GNL on it.
** @param char** arg A file path, or decimal representation of an arbitrary file descriptor.
** @return 0 if the test was performed throughout, an error code otherwise;
*/
int	TestOneArg(char* arg){
	errno = 0;
	TestOneFile(arg);

	if (errno == 2){
		int fd;
		errno = 0;
		fd = atoi(arg);
		if (errno == 22)
			errno = 2;
		else {
			TestOneFd(fd);
			return 0;
		}
	}

	return errno;
}
