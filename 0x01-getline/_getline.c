#include "_getline.h"
#include <string.h>
/**
 * _getline - Gets a line from an input
 * @fd: file descriptor number
 *
 * Return: pointer to the 'line'
 */
char *_getline(const int fd)
{
	static long chr;
	int i = 0;
	int qr = 0;
	char *buf = malloc(sizeof(char) * READ_SIZE);
	char *mybuf = malloc(sizeof(char) * 512);

	if (fd == -1)
	{
		chr = 0;
		free(buf);
		free(mybuf);
		return (NULL);
	}
	if (!buf)
		return (NULL);
	if (!mybuf)
		return (NULL);
	while ((qr = read(fd, buf, READ_SIZE) > 0))
	{
		chr++;
		if (buf[0] != '\n' && buf[0] != EOF)
		{
			strcpy(&mybuf[i], &buf[0]);
		}
		else
		{
			mybuf[i] = '\0';
			break;
		}
		i++;
	}

	if (qr == 0 || qr == -1)
	{
		free(buf);
		free(mybuf);
		return (NULL);
	}
	free(buf);
	return (mybuf);
}
