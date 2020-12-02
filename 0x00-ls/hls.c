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
	while ((read = readdir(dir)) != NULL)
	{
		prtfnms(read);
	}
	printf("\n");
	return (0);
}

int prtfnms(struct dirent *read)
{
	struct stat sb;

	lstat(read->d_name, &sb);
	printf("%s ", read->d_name);
	return (0);
}
