#include "get_next_line.h"

char *final_line(char *remainder, char *line)
{
    line = ft_strdup(remainder);
    free(remainder);
    remainder = NULL;
    return (line);
    
}

char *update_remainder(char *remainder, char *line)
{
	int line_index;
	int len;
	char *new_remainder;

	if (!remainder || !line)
		return (NULL);
	line_index = find_newline(remainder);
	if (line_index == -1)
		return (free(remainder), NULL);
	len = ft_strlen(remainder) - line_index;
	if (len <= 0)
		return (free(remainder), NULL);
	new_remainder = ft_substr(remainder, (line_index + 1), len);
	if (!new_remainder)
		return (free(new_remainder), NULL);
	new_remainder[len] = '\0';
	return (free(remainder), new_remainder);
}

char *extract_line(char *remainder)
{
    int    	newline_index;
    int    	index;
    char 	*line;

    if (!remainder)
        return (NULL);
    newline_index = find_newline(remainder);
    index = 0;
    line = (char *)malloc(sizeof(char) * (newline_index + 1));
    if (!line)
        return (free(line), NULL);
    while (index <= newline_index)
    {
        line[index] = remainder[index];
        index++;
    }
    line[index] = '\0';
    return (line);
}

char *ft_read(int fd, char *remainder)
{
    char *buff;
	char *tmp;
    int bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buff)
        return (NULL);
    bytes_read = 1;
    while (bytes_read > 0 && find_newline(buff) == -1)
    {
        bytes_read = read(fd, buff, BUFFER_SIZE);
        if (bytes_read == (-1))
            return (free(buff), NULL);
        buff[bytes_read] = '\0';
		tmp = remainder;
        remainder = ft_strjoin(remainder, buff);
		free(tmp);
        if (!remainder)
            return (free(buff), NULL);
        if (find_newline(remainder) != -1)
            break;
    }
    return (free(buff), remainder);
}

char *get_next_line(int fd)
{
    static char *remainder;
    char *line;

    line = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (remainder && find_newline(remainder) != -1)
    {
        line = extract_line(remainder);
        remainder = update_remainder(remainder, line);
        return (line);
    }
    remainder = ft_read(fd, remainder);
    if (!remainder)
        return (NULL);
    if (find_newline(remainder) == -1)
    {
        if (ft_strlen(remainder) > 0)
            return (final_line(remainder, line));
        return (NULL);
    }
    line = extract_line(remainder);
    remainder = update_remainder(remainder, line);
    return (line);
}

int main()
{
    int fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    char *str;
    while ((str = get_next_line(fd)) != NULL)
    {
        printf("%s", str);
        free(str);
    }

    close(fd);
    return 0;
}
