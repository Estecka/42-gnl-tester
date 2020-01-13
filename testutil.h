/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_util.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:32:57 by abaur             #+#    #+#             */
/*   Updated: 2020/01/13 14:13:52 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <ctype.h>

#include "logutil/logutil.h"
#include "../get_next_line.h"

/*
** The width of the display
*/
#define COLCOUNT 42

short printline_row(const char* line);

int TestOneFile(char* path);
int TestWovenFiles(int filecount, char** pathes);
