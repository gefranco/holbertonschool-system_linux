#include "_getline.h"

/*int main(void)
{
    int fd;
    char *line;

    fd = open("1-main.c", 0);
    while ((line = _getline(fd)))
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}
*/

char *_getline(const int fd)
{
	char *buf = malloc(sizeof(char) * READ_SIZE);
	char *mybuf = malloc(sizeof(char) * 512);
	static long chr;
	int i = 0;
	(void) fd;
	
	if(read(fd, buf, READ_SIZE) == 0)
		return NULL;
	
	lseek(fd, chr, 0);
	while(read(fd, buf, READ_SIZE)!=0)
	{	
		
		chr++;
		if(buf[0] != '\n')
		{
			mybuf[i] = buf[0];
			
		}else
		{
			mybuf[i + 1] = '\0';
			break;
		}
		
		i++;	
	}

			
	return mybuf;
}
