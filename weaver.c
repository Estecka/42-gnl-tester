/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weaver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:19:26 by abaur             #+#    #+#             */
/*   Updated: 2020/01/14 14:04:32 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testutil.h"
#include <strings.h>

typedef struct s_wovenfile {
	char* name;
	int	fd;
	int status;

	int	linecount;
	char** lines;
} wovenfile;


static wovenfile* files = NULL;

/*
** Interprets an argument either as a path or file descriptor.
** Sets errno if the argument is invalid.
** @return The matching fd, -1 otherwise.
*/
static int	ArgToFd(char *arg)
{
	int	fd;
	errno = 0;

	fd = open(arg, O_RDONLY);

	if (errno == 2){
		errno = 0;
		fd = atoi(arg);
		if (errno == 22)
			errno = 2;
	}
	return errno ? -1 : fd;
}

/*
** Gets a file descriptor for each argument, and store them into g_files.
** If an argument is invalid, errno is set.
** @return The index of the invalid argument, -1 otherwise;
*/
static int Initfiles (int argc, char** args){
	bzero(files, argc * sizeof(wovenfile));
	for (int i=0; i<argc; i++){
		files[i].fd = ArgToFd(args[i]);
		if (files[i].fd < 0)
			return i;
		files[i].name = args[i];
		files[i].status = 1;
	}
	return -1;
}

/*
** Run GNL successively on every files until all end of files are reached.
** @pram int argc The length of args;
** @param char** args a list of file pathes or file descriptor to test.
** @return
** 	- 0 if the tests were performed throughout.
** 	- An index from args, if a a file could not be opened.
*/
int TestWovenArgs(int argc, char** args){
	int err;

	files = malloc(argc * sizeof(wovenfile));
	if (!files)
		return errno;
	err = Initfiles(argc, args);
	if (err >= 0)
		return err;

	short allClear = 1;
	while (allClear)
	{
	}
	//...
	return 0;
}
