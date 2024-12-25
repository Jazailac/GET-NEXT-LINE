/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 08:59:06 by amait-ou          #+#    #+#             */
/*   Updated: 2024/12/16 00:29:11 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*ft_strchr(char*s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*get_one_line(char *r);
char	*free_remainder(char *remainder);
size_t	ft_strlen(char *s);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#endif