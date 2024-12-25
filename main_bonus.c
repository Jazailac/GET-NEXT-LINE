#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

int main(void)
{
	// Test multiple file descriptors
	int fd1, fd2, fd3;
	char *line;

	// Open three different files for testing
	fd1 = open("file1.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	fd3 = open("file3.txt", O_RDONLY);

	if (fd1 == -1 || fd2 == -1 || fd3 == -1)
	{
		perror("Error opening files");
		return 1;
	}

	printf("--- Testing Multiple File Descriptors ---\n");

	// Read from first file
	printf("Reading from file1.txt:\n");
	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("File1: %s", line);
		free(line);
	}

	// Read from second file
	printf("\nReading from file2.txt:\n");
	while ((line = get_next_line(fd2)) != NULL)
	{
		printf("File2: %s", line);
		free(line);
	}

	// Read from third file
	printf("\nReading from file3.txt:\n");
	while ((line = get_next_line(fd3)) != NULL)
	{
		printf("File3: %s", line);
		free(line);
	}

	// Close file descriptors
	close(fd1);
	close(fd2);
	close(fd3);

	// Test with non-existent file descriptor
	printf("\n--- Testing Invalid File Descriptor ---\n");
	line = get_next_line(999);
	if (line == NULL)
		printf("Correctly handled invalid file descriptor\n");

	return 0;
}