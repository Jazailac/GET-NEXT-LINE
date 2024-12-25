/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 08:58:43 by amait-ou          #+#    #+#             */
/*   Updated: 2024/12/16 00:26:32 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_remainder(int fd, char *remainder)
{
	char	*buffer;
	int		rd;

	rd = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (rd > 0 && !ft_strchr(remainder, '\n'))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == 0)
		{
			free(buffer);
			return (remainder);
		}
		if (rd == -1)
			return (free(remainder), free(buffer), NULL);
		buffer[rd] = '\0';
		remainder = ft_strjoin(remainder, buffer);
	}
	free(buffer);
	return (remainder);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remainder;

	if (fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = get_remainder(fd, remainder);
	line = get_one_line(remainder);
	remainder = free_remainder(remainder);
	return (line);
}
