#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>

int hls(int argc, char **argv)
{
	struct dirent *read;
	DIR *dir;

	dir = opendir(".");
	while ((read = readdir(dir)) != NULL)
	{
		prtfnms(read);
	}
	printf("\n");
}

int prtfnms(struct dirent *read)
{
	struct stat sb;

	lstat(read->d_name, &sb);
	printf("%s ", read->d_name);
}
