/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weaver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:19:26 by abaur             #+#    #+#             */
/*   Updated: 2020/01/14 16:22:24 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testutil.h"
#include <strings.h>

typedef struct s_wovenfile {
	char* name;
	int	fd;
	int status;

	int	capacity;
	int	linecount;
	char** content;
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
** Makes sure the file's buffer can accept at least one additional line.
** The buffer capacity is doubled if too small.
** @param wovenfile* file The file whose buffer to check.
** @return 0, or an error code if mallocation failed.
*/
static short IncrementBuffer(wovenfile* file){
	if (files->content == NULL){
		files->capacity = 32;
		files->content = malloc(32 * sizeof(char*));
	} else if (files->linecount == files->capacity) {
		int capacity = file->capacity;
		char** prev = files->content;
		char** next = malloc(2 * capacity * sizeof(char*));
		if (!next)
			return errno;
		for (int i=0; i<capacity; i++)
			next[i] = prev[i];
		files->content = next;
		files->capacity *= 2;
		free(prev);
	}
	return 0;
}

/*
** Runs GNL once on the given file, and stores the result in g_files.
** The file descriptor is assumed to be valid.
** @param wovenfile* file The file to test.
** @return The return value of GNL. -1 in case of error.
*/
static int TestOneWeave(wovenfile* file){
	char* result = NULL;
	int gnl;
	int err;

	gnl = get_next_line(file->fd, &result);
	file->status = gnl;

	err = IncrementBuffer(file);
	if (err)
		return -1;

	file->content[file->linecount] = result;
	file->linecount += 1i;

	return gnl;
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
		allClear = 0;
		for (int i=0; i<argc; i++){
			wovenfile* file = files + i;
			if (file->status > 0){
				allClear = 1;
				err = TestOneWeave(file);
				if (err < 0){
					allClear = 0;
					break;
				}
			}
		}
	}
	//...
	return 0;
}
