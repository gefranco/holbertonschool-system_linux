#include "hls.h"
#include <errno.h>

/**
 * hls - Entry point for hls
 * @argc: total of arguments
 * @argv: arguments
 *
 * Return: 0 if no errors.
 */
int hls(int argc, char **argv)
{
	
        char *namedir = ".";
	int i;
	(void) argc;
	(void) argv;

        if(argc > 2)
        {

                for(i = 1; i < argc - 1; i++)
                {
                        prtcntdir(argv[i],1);

                        printf("\n");
                }
                prtcntdir(argv[i], 1);
        }
        else if (argc > 1)
                prtcntdir(argv[1], 0);
        else
                prtcntdir(namedir, 0);	
	return (0);
}


int prtcntdir(char *name, int prtname)
{
	struct dirent *read;
        DIR *dir;
	dir = opendir(name);
	
        if (!dir)
	{
		if(errno == 2)
			fprintf(stderr, "hls: cannot access %s: "
						"No such file or directory\n", name);
                if(errno == 13)
			fprintf(stderr, "hls: cannot access %s: "
						"No such file or directory\n", name);
		return (2);
	}
        if(prtname)
		printf("%s:\n", name);
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
	lstat (read->d_name, &sb);
		printf("%s\t", read->d_name);
	return (0);
}
