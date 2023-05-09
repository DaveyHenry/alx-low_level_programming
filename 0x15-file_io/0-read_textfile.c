#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: name of the file to read
 * @letters: number of letters it should read and print
 *
 * Return: actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t lenr, lenw;
	char *buffer;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	struct stat st;
	if (fstat(fd, &st) == -1)
	{
		close(fd);
		return (0);
	}

	size_t filesize = st.st_size;
	if (letters > filesize)
		letters = filesize;

	buffer = malloc(sizeof(char) * (filesize + 1));
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}

	lenr = read(fd, buffer, letters);
	close(fd);

	if (lenr == -1)
	{
		free(buffer);
		return (0);
	}

	buffer[lenr] = '\0';

	lenw = write(STDOUT_FILENO, buffer, lenr);
	free(buffer);

	if (lenw == -1 || (size_t) lenw != lenr)
		return (0);

	return (lenw);
}
