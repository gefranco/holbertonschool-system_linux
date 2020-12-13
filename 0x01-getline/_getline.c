#include "_getline.h"


char *_getline(const int fd)
{
	char buf[READ_SIZE];
	 
	char *line = malloc(sizeof(char) * READ_SIZE);
	char c;
	int i,j;
	static int tr;
	j = 0;
	read(fd, &buf, READ_SIZE);
	if(buf[tr] == EOF)
		return NULL;	
	if(buf[tr] =='\n')
	{
		line[0] = '\n';
		line[1] = '\0';
		tr++;
		return line;
	}
	for(j = 0, i = tr; i < READ_SIZE + tr - 1 && (c = buf[i]) != EOF && c != '\n';i++, j++)	
	{
		line[j] = c;
	}
	tr += j;
	if (c =='\n'){
		line[j] = '\n';
		
	}
	if (c == EOF){
		return NULL;
	}
	line[j] = '\0';
	tr+=1;	
	return line;

}
