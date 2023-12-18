/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancalvo <mancalvo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:06:45 by mancalvo          #+#    #+#             */
/*   Updated: 2023/12/15 14:06:46 by mancalvo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int main()
{
	int fd1;
	int fd2;
	int fd3;
	char *new_line1; 
	char *new_line2; 	
	char *new_line3; 

	fd1 = open ("fd1.txt", O_RDONLY);
	fd2 = open ("fd2.txt", O_RDONLY);
	fd3 = open ("fd3.txt", O_RDONLY);

	new_line1 = get_next_line(fd1);
	new_line2 = get_next_line(fd2);
	new_line3 = get_next_line(fd3);
	
	while(new_line1 || new_line2 || new_line3)
	{
		printf("%s", new_line1);
		printf("%s", new_line2);
		printf("%s", new_line3);
		free(new_line1);
		free(new_line2);
		free(new_line3);
		new_line1 = get_next_line(fd1);
		new_line2 = get_next_line(fd2);
		new_line3 = get_next_line(fd3);
	}
	close(fd1);
	close(fd2);
	close(fd3);		
	return (0);

}