/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancalvo <mancalvo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:13:58 by mancalvo          #+#    #+#             */
/*   Updated: 2023/12/14 14:54:07 by mancalvo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_free(char *str)
{
	free(str);
	str = NULL;
	return (NULL);
}

char	*read_buffer_join(int fd, char *storage)
{
	int		index;
	char	*buffer;

	if (fd < 0)
		return (NULL);
	index = 1;
	buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(storage));
	buffer[0] = '\0';
	while (!ft_strchr(buffer, '\n') && index > 0)
	{
		index = read (fd, buffer, BUFFER_SIZE);
		if (index > 0)
		{
			buffer[index] = '\0';
			storage = ft_strjoin(storage, buffer);
		}
	}
	ft_free(buffer);
	if (index == -1)
		return (ft_free(storage));
	return (storage);
}

char	*pull_new_line(char *storage)
{
	char	*line;
	char	*ptr;
	size_t	len;

	ptr = ft_strchr(storage, '\n');
	len = ptr - storage + 1;
	line = ft_substr(storage, 0, len);
	if (!line)
		return (ft_free(storage));
	return (line);
}

char	*storage_cleaner(char *storage)
{
	char	*ptr;
	char	*new_storage;
	size_t	len;

	ptr = ft_strchr(storage, '\n');
	if (!ptr)
		return (ft_free(storage));
	len = (ptr - storage) + 1;
	if (!storage[len])
		return (ft_free(storage));
	new_storage = ft_substr(storage, len, ft_strlen(storage) - len);
	if (!new_storage)
		return (ft_free(storage));
	ft_free(storage);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage[MAX_FD];
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if ((storage[fd] && !ft_strchr(storage[fd], '\n')) || !storage[fd])
		storage[fd] = read_buffer_join(fd, storage[fd]);
	if (!storage[fd])
		return (ft_free(storage[fd]));
	new_line = pull_new_line(storage[fd]);
	if (!new_line)
		return (ft_free(storage[fd]));
	storage[fd] = storage_cleaner(storage[fd]);
	return (new_line);
}
