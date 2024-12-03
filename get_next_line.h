#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1337
#endif

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char    *ft_substr(const char *s, unsigned int start, size_t len);
char    *ft_strjoin(const char *s1, const char *s2);
char    *ft_strdup(const char *s1);
void    *ft_memcpy(void *dst, const void *src, size_t n);
size_t  ft_strlen(const char *s);
int     find_newline(char *read);
char    *update_remainder(char *remainder, char *line);
char    *get_next_line(int fd);

#endif