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
	int i, to, shwhdn, almsa, tfa, r, dtlf;

	char targse;

	(void) argc;
	(void) argv;
		
	i = shwhdn = to = targse = almsa = tfa = r = dtlf = 0;
        targse = mngargse(argc, argv);
	
	to = topts(argc, argv);
	
	switch (targse){
	case '1':
		spcprt = '\n';
		break;
	case '2':
		shwhdn = '1';
		break;
	case '3':
		spcprt = '\n';
                shwhdn = 1;
		break;
	case '4':
		almsa = 1;
		break;
	case '5':
		almsa = 1;
                spcprt = '\n';
		break;
	case '6':
		dtlf = 1;
		break;
	default:
		fprintf(stderr, "hls: invalid option -- '%c'\n", targse);
		exit(2);
		break;
	}
	
	if(targse == 0 && to > 0)
	{
		return(2);
	}
	
	tfa = tofiargs(argc, argv);	
	if(tfa > 1)
        {
                for(i = 1; i < argc - 1; i++)
                {
                        if((_strlen(argv[i]) == 1 && argv[i][0] == '-') || (_strlen(argv[i]) > 0 && argv[i][0] != '-'))
			{
				r = prtcntdir(argv[i], 1, spcprt, shwhdn, almsa, dtlf);
				
				if(mrprms(i, argc, argv) && r == 0)
                                        printf("\n");		
			
			}
                }
		if((_strlen(argv[i]) == 1 && argv[i][0] == '-') || (_strlen(argv[i]) > 0 && argv[i][0] != '-'))
	                prtcntdir(argv[i], 1, spcprt,shwhdn, almsa, dtlf);
        }
	else if (tfa > 0)
        {
		for(i = 1; i < argc; i++)
                {
                        if((_strlen(argv[i]) == 1 && argv[i][0] == '-') || (_strlen(argv[i]) > 0 && argv[i][0] != '-'))
                        {
                                prtcntdir(argv[i], 0, spcprt, shwhdn, almsa, dtlf);

                        }
                }
		
	}		
	else if (tfa == 0){
                prtcntdir(namedir, 0, spcprt, shwhdn, almsa, dtlf);	
	}
	else {
		printf("!!!\n");
	}
	return (0);
}
int topts(int argc, char *argv[])
{
	int t, i;
        (void) argc;
        (void) argv;
        t = 0;
        for(i = argc - 1; i > 0 ;i--){
                if(_strlen(argv[i]) > 1 && argv[i][0] == '-')
                        t++;
        }
        return (t);
}
int tofiargs(int argc, char *argv[])
{
	int t, i;
	(void) argc;
	(void) argv;
	t = 0;
	for(i = argc - 1; i > 0 ;i--){
		if(_strlen(argv[i]) == 1 && argv[i][0] == '-')
			t++;
		else if(_strlen(argv[i]) > 0 && argv[i][0] != '-')
			t++;
	}
	return (t);
}
int mrprms(int i, int argc, char *argv[])
{
	for(i = i + 1; i < argc; i++)
	if((_strlen(argv[i]) == 1 && argv[i][0] == '-') || (_strlen(argv[i]) > 0 && argv[i][0] != '-'))
		return (1);
	return (0);
}
char mngargse(int argc, char *argv[])
{
	
	int i = 0;
	for(i = argc - 1; i > 0 ;i--){
		if(argv[i][0]=='-'){
			if (argv[i][1] == 'a' && argv[i][2] == '1')
			{
                                return ('3');
			}else if (argv[i][1] == 'A' && argv[i][2] == '1')
				return ('5');
			else if(argv[i][1] == '1'){
				return ('1');	
			}else if (argv[i][1] == 'a'){
				return ('2');
			}else if (argv[i][1] == 'A'){
				return ('4');
			}else if (argv[i][1] == 'l')
				return ('6');
			else
				return argv[i][1];	
		}

	
	}
	return ('\0');
}


int prtcntdir(char *name, int prtname, char spcprt, int shwhdn, int almsa, int sdf)
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
			return(2);
		}
		
	}
        if(prtname)
		printf("%s:\n", name);
        while ((read = readdir(dir)) != NULL)
        {
                if (read->d_name[0] == '.' && shwhdn){
			if(sdf)
				prtdetlf(read, spcprt);
                        else
				prtfnms(read, spcprt);
		}
		if (read->d_name[0] != '.'){
			if(sdf)
				prtdetlf(read, spcprt);
			else
				prtfnms(read, spcprt);
		}
		if (read->d_name[0] == '.' && _strlen(read->d_name) > 2 && almsa){
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

int prtdetlf(struct dirent *read, char space)
{
	struct stat sb;           
	char *time;
	struct passwd *user;
	(void) space;
	lstat(read->d_name, &sb);
      if((sb.st_mode & S_IFMT) == S_IFDIR)
         printf("d");
      else
         printf("-");
      if(sb.st_mode & S_IRUSR)
         printf("r");
      else
         printf("-");
      if(sb.st_mode & S_IWUSR)
         printf("w");
      else
         printf("-");
      if(sb.st_mode & S_IXUSR)
         printf("x");
      else 
         printf("-");

      printf(" ");
      
      
      user = getpwuid(sb.st_uid);
      printf("%s ",user->pw_name);
      printf("%s ", read->d_name);
      printf("%ld", sb.st_size);

      time = ctime(&(sb.st_mtime));
      printf(" %s",time);
      
   
   return (0);
}
