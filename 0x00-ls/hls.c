#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
int prtfnms(struct dirent *read);

int ldir(char *dir_name);
int hls(int argc, char **argv)
{
	struct dirent *read;
	DIR *dir;
	int i, j = 0;

	(void) argc;
	(void) argv;
	i = ldir(".");

	dir = opendir(".");
	for (j = 0; j < i - 1; j++)
	{
		read = readdir(dir);
		prtfnms(read);
	}
	read = readdir(dir);
	printf("%s\n", read->d_name);
	closedir(dir);
	return (0);
}

int prtfnms(struct dirent *read)
{
	printf("%s\t", read->d_name);
	return (0);
}

int ldir(char *dir_name)
{
	struct dirent *read;
	int i = 0;
	DIR *dir = opendir(dir_name);
        if(dir == NULL)
        {
                fprintf(stderr, "hls: cannot open directory .: Permission denied\n");
                return (1);
        }
        while ((read = readdir(dir)) != NULL)
        {
                i++;
        }
	closedir(dir);
	return i;
}
