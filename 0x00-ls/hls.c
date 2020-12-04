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
	char spcprt = '\t';
	int i, targse = 0;
	(void) argc;
	(void) argv;

        targse = mngargse(argc, argv);
	if (targse > 0 ){
		spcprt = '\n';
	}
	if(argc - targse > 2)
        {

                for(i = 1; i < argc - 1; i++)
                {
                        if(argv[i][0] != '-')
				prtcntdir(argv[i], 1, spcprt);

                        printf("\n");
                }
                prtcntdir(argv[i], 1, spcprt);
        }
        else if (argc - targse  > 1)
	{
		if(argv[1][0]!='-')
                	prtcntdir(argv[1], 0, spcprt);
		else
			prtcntdir(argv[2], 0, spcprt);
        }
	else
                prtcntdir(namedir, 0, spcprt);	
	return (0);
}

int mngargse(int argc, char *argv[])
{
	
	int i = 0;
	int totalargs = 0;
	for(i = argc - 1; i > 0 ;i--){
		if(argv[i][0]=='-'){
			if(argv[i][1] == '1'){
				totalargs++;	
			}
		}
	}
	return (totalargs); 
}

int mngargss(int argc, char *argv[])
{

        int i = 0;
        int totalargs = 0;
        for(i = 1; i < argc - 1 ;i++){
                if(argv[i][0]=='-'){
                        if(argv[i][1] == '1'){
                                totalargs++;
                        }
                }
        }
        return (totalargs);
}

int prtcntdir(char *name, int prtname, char spcprt)
{
	struct dirent *read;
        DIR *dir;
	dir = opendir(name);
	
        if (!dir)
	{
		
		if(errno == 2)
		{
			fprintf(stderr, "hls: cannot access %s: "
					"No such file or directory\n", name);
                	return (2);
		}
		if(errno == 13){
			fprintf(stderr, "hls: cannot open directory %s: "
						"Permission denied\n", name);
			return (2);

		}
		else{
			printf("%s\n", name);
			return(0);
		}
		
	}
        if(prtname)
		printf("%s:\n", name);
        while ((read = readdir(dir)) != NULL)
        {
                if (read->d_name[0] != '.')
                {
                        prtfnms(read, spcprt);
                }
        }
	if(spcprt != '\n')
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
int prtfnms(struct dirent *read,char space)
{
	struct stat sb;
	
	lstat (read->d_name, &sb);
		printf("%s%c", read->d_name, space);
	return (0);
}
