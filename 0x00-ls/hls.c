#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
int prtfnms(struct dirent *read);

int hls(int argc, char **argv)
{
	struct dirent *read;
	DIR *dir;

	(void) argc;
	(void) argv;
	dir = opendir(".");
	if(dir == NULL)
		return (1);
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
	printf("%s  ", read->d_name);
	return (0);
}
