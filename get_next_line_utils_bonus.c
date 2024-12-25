/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 23:46:03 by jazailac          #+#    #+#             */
/*   Updated: 2024/12/16 00:26:49 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		++i;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	char	*p;

	if (!s)
		return (0);
	p = (char *)s;
	while (*p && *p != (char)c)
		++p;
	if (*p == (char)c)
		return (p);
	return ((void *)0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*p;

	p = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!p)
		return ((void *)0);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		p[i] = s1[i];
		++i;
	}
	while (s2[j])
		p[i++] = s2[j++];
	p[i] = '\0';
	free(s1);
	return (p);
}

char	*get_one_line(char *remainder)
{
	char	*line;
	int		i;

	if (!remainder)
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		++i;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
	{
		line[i] = remainder[i];
		i++;
	}
	if (remainder[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*free_remainder(char *remainder)
{
	char	*new_remainder;
	int		i;
	int		j;

	if (!remainder)
		return (NULL);
	i = 0;
	j = 0;
	while (remainder[i] != '\n' && remainder[i])
		++i;
	if (!remainder[i] || (remainder[i] == '\n' && remainder[i + 1] == '\0'))
	{
		free(remainder);
		return (NULL);
	}
	new_remainder = malloc((ft_strlen(remainder) - i));
	if (new_remainder)
	{
		while (remainder[++i])
			new_remainder[j++] = remainder[i];
		new_remainder[j] = '\0';
	}
	free(remainder);
	return (new_remainder);
}
