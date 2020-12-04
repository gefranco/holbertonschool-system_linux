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

	(void) argc;
	(void) argv;

	dir = opendir(".");
	if(!dir)
		return(2);
	while ((read = readdir(dir)) != NULL)
	{
		if (read->d_name[0] != '.') 
		{
			prtfnms(read);
		}
	}
	printf("\n");
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
	struct stat sb;
	lstat(read->d_name, &sb);
		printf("%s\t", read->d_name);
	return (0);
}
