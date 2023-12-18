/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_de_nuevo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancalvo <mancalvo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:10:11 by mancalvo          #+#    #+#             */
/*   Updated: 2023/12/15 13:14:05 by mancalvo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd;
	char *next_line;
	int i;

	i = 1;
	fd = open ("file.txt", O_RDONLY);
	next_line = get_next_line(fd);
	while (next_line)
	{
		printf("Esta es la línea: %d", i);
		printf("%s", next_line);
		free(next_line);
		next_line = get_next_line(fd);
		i++;
	}
	close(fd);
	return(0);
}