/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancalvo <mancalvo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:41:17 by mancalvo          #+#    #+#             */
/*   Updated: 2023/12/15 18:00:25 by mancalvo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd;
	char *new_line;
 	int i;

	i = 1; 
	//fd = open ("file.txt", O_RDONLY);
	new_line = get_next_line(fd);
	while (new_line)
	{
		printf("esta es la línea número: %d", i);
		printf("%s", new_line);
		free(new_line);
		new_line = get_next_line(fd);
		i++;
	} 
	
/* 	if (new_line)
	{
		printf("Esta es la next_line: %s", new_line);
		free(new_line);
		new_line = get_next_line(fd);
	}
	if (new_line)
	{
		printf("Esta es la next_line: %s", new_line);
		free(new_line);
		new_line = get_next_line(fd);
	}
	if (new_line)
	{
		printf("Esta es la next_line: %s", new_line);
		free(new_line);
		new_line = get_next_line(fd);
	}
	if (new_line)
	{
		printf("Esta es la next_line: %s", new_line);
		free(new_line);
		new_line = get_next_line(fd);
	}
	if (new_line)
	{
		printf("Esta es la next_line: %s", new_line);
		free(new_line);
		new_line = get_next_line(fd);
	}
	if (new_line)
	{
		printf("Esta es la next_line: %s", new_line);
		free(new_line);
		new_line = get_next_line(fd);
	}
	if (new_line)
	{
		printf("Esta es la next_line: %s", new_line);
		free(new_line);
		new_line = get_next_line(fd);
	}
	if (new_line)
	{
		printf("Esta es la next_line: %s", new_line);
		free(new_line);
		new_line = get_next_line(fd);
	}
	if (new_line)
	{
		printf("Esta es la next_line: %s", new_line);
		free(new_line);
		new_line = get_next_line(fd);
	} */

	close (fd);
	return(0);	
}