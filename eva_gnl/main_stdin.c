/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancalvo <mancalvo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:06:40 by mancalvo          #+#    #+#             */
/*   Updated: 2023/12/15 14:13:40 by mancalvo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd;
	char *new_line;

	fd = 0;
	new_line = get_next_line(fd);
	printf("línea en stdin: %s", new_line);
	free(new_line);
	new_line = get_next_line(fd);
	printf("línea en stdin: %s", new_line);
	free(new_line);
	return (0);	
}