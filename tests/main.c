#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>


void ll()
{
	system("leaks a.out");
}
int main(int argc, char **argv) {
    int fd;
    char *line;
    int line_count = 0;

    // Check if a filename was provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the file
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Read lines until get_next_line returns NULL
    while ((line = get_next_line(fd)) != NULL) {
        printf("Line %d: %s\n", ++line_count, line);
        free(line);  // Don't forget to free each line
    }

    // Close the file
    close(fd);

    printf("Total lines read: %d\n", line_count);

    return 0;
}