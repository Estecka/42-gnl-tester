/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 14:54:44 by abaur             #+#    #+#             */
/*   Updated: 2020/01/02 15:12:16 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
int	get_next_line(int, char**);

void TestOneGNL(){
	char* line = NULL;
	int r;

	r = get_next_line(0, &line);

	if (r == 1)
		printf("%s\n", line);
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
