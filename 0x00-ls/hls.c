#include "hls.h"
/**
 * hls - Entry point for hls
 * @argc: total of arguments
 * @argv: arguments
 *
 * Return: 0 if no errors.
 */
int hls(int argc, char **argv)
{
	struct dirent *read;
	DIR *dir;
	int i, j = 0;

	(void) argc;
	(void) argv;
	i = ldir(".");

	dir = opendir(".");
	for (j = 0; j < i - 1 ; j++)
	{
		read = readdir(dir);
		prtfnms(read);
	}
	read = readdir(dir);
	printf("%s\n", read->d_name);
	closedir(dir);
	return (0);
}

/**
 * prtfnms - print the name of the file
 * @read: dirent structure
 *
 * Return: 0 if no errors.
 */
int prtfnms(struct dirent *read)
{
	printf("%s\t", read->d_name);
	return (0);
}
/**
 * ldir - Returns the number of files in a directory
 * @dir_name: dir name
 *
 * Return: total files.
 */
int ldir(char *dir_name)
{
	struct dirent *read;
	int i = 0;
	DIR *dir = opendir(dir_name);

	if (dir == NULL)
	{
		fprintf(stderr, "hls: error");
		return (1);
	}
	while ((read = readdir(dir)) != NULL)
	{
		i++;
	}
	closedir(dir);
	return (i);
}
