#include "get_next_line.h"
#include <stdio.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	substr_len;
	char	*substr;

	substr_len = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= ft_strlen(s))
	{
		substr = malloc(1);
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr); 
	}
	substr_len = len;
	if (substr_len + start >= s_len)
		substr_len = s_len - start;
	substr = malloc(sizeof(char) * (substr_len + 1));
	if (!substr)
		return (NULL);
	ft_memcpy(substr, s + start, substr_len);
	substr[substr_len] = '\0';
	return (substr);
}

int find_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index])
	{
		index++;
	}
	return (index);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned char		*s;
	size_t				index;

	if (!src && !dst)
		return (dst);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (s == d)
		return (dst);
	index = 0;
	while (index < n)
	{
		d[index] = s[index];
		index++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	size_t	index;
	char	*duplicated;
	size_t	len;


	index = 0;
	len = ft_strlen(s1);
	duplicated = (char *)malloc(sizeof(char) * (len + 1));
	if (!duplicated)
		return (NULL);
	while (s1[index])
	{
		duplicated[index] = s1[index];
		index++;
	}
	duplicated[index] = '\0';
	return (duplicated);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t			index;
	char			*str;

	if (!s2 && !s1)
		return (NULL);
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	index = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	while (s1[index])
	{
		str[index] = s1[index];
		index++;
	}
	while (*s2)
		str[index++] = *s2++;
	str[index] = '\0';
	return (str);
}