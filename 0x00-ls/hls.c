#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
int prtfnms(struct dirent *read);

int hls(int argc, char **argv)
{
	struct dirent *read;
	DIR *dir;

	(void) argc;
	(void) argv;
	dir = opendir(".");
	if (dir == NULL)
	{
		fprintf(stderr, "hls: cannot open directory .: Permission denied\n");
		return (1);
	}
	while ((read = readdir(dir)) != NULL)
	{
		prtfnms(read);
	}
	printf("\n");
	closedir(dir);
	return (0);
}

int prtfnms(struct dirent *read)
{
	if ( strcmp(read->d_name, ".") && strcmp(read->d_name, "..") )
		printf("%s\t", read->d_name);
	return (0);
}
