/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancalvo <mancalvo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:14:38 by mancalvo          #+#    #+#             */
/*   Updated: 2023/12/13 15:30:10 by mancalvo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == (char)c)
			return (&str[i]);
	if ((char)c == '\0')
		return (&str[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*join;

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = malloc (sizeof(char) * 1);
		if (!s1)
			return (ft_free(s1));
		s1[0] = '\0';
	}
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (ft_free(s1));
	while (s1[++i])
		join[i] = s1[i];
	while (s2[++j])
		join[i + j] = s2[j];
	join[i + j] = '\0';
	ft_free(s1);
	return (join);
}

char	*ft_substr(char *str, size_t start, size_t len)
{
	size_t	i;	
	size_t	j;
	char	*sub;

	i = -1;
	j = 0;
	if (!str)
		return (ft_free(str));
	if (start + len > ft_strlen(str))
		len = ft_strlen(str) - start;
	if (start > ft_strlen(str) || len < 0)
		len = 0;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (ft_free(str));
	while (str[++i])
		if (i >= start && j < len)
			sub[j++] = str[i];
	sub[j] = '\0';
	return (sub);
}
