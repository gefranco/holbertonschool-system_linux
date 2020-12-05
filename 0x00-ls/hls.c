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
	int i, targse, shwhdn = 0;
	(void) argc;
	(void) argv;

        targse = mngargse(argc, argv);
	if (targse == 1 ){
		spcprt = '\n';
	}
	if (targse == 2)
		shwhdn = 1;
	if (targse == 3){
		spcprt = '\n';
		shwhdn = 1;
	}
	if(argc > 3)
        {
                for(i = 1; i < argc - 1; i++)
                {
                        if(argv[i][0] != '-')
			{
				prtcntdir(argv[i], 1, spcprt, shwhdn);
				
				
				if(mrprms(i, argc, argv))
                                        printf("\n");
				
					
			
			}
                }
		if(argv[i][0] != '-')
	                prtcntdir(argv[i], 1, spcprt,shwhdn);
        }
	else if (argc  > 1)
        {
		for(i = 1; i < argc; i++)
                {
                        if(argv[i][0] != '-')
                        {
                                prtcntdir(argv[i], 0, spcprt, shwhdn);





                        }
                }
		
	}		
	else if (argc > 0){
                prtcntdir(namedir, 0, spcprt, shwhdn);	
	}
	else {
		printf("!!!\n");
	}
	return (0);
}
int mrprms(int i, int argc, char *argv[])
{
	for(i = i + 1; i < argc; i++)
	if(argv[i][0] != '-')
		return (1);
	return (0);
}
int mngargse(int argc, char *argv[])
{
	
	int i = 0;
	int totalargs = 0;
	for(i = argc - 1; i > 0 ;i--){
		if(argv[i][0]=='-'){
			if (argv[i][1] == 'a' && argv[i][2] == '1')
                                return 3;
			if(argv[i][1] == '1'){
				return 1;	
			}if (argv[i][1] == 'a')
				return 2;
		}
	}
	return (totalargs); 
}


int prtcntdir(char *name, int prtname, char spcprt, int shwhdn)
{
	struct dirent *read;
        DIR *dir;
	dir = opendir(name);
	(void) shwhdn;	
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
                if (read->d_name[0] == '.' && shwhdn)
                {
                        prtfnms(read, spcprt);
                }
		if (read->d_name[0] != '.')
			prtfnms(read, spcprt);
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
