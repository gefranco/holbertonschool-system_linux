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
	int qr = 0;
	(void) fd;
		
	/*if(read(fd, buf, READ_SIZE) == 0)
		return NULL;
	*/
	/*lseek(fd, chr, 0);*/
	while((qr =read(fd, buf, READ_SIZE) > 0))
	{	
		
		chr++;
		if(buf[0] != 10 && buf[0] != 12)
		{
			mybuf[i] = buf[0];
			
		}else
		{
			mybuf[i + 1] = '\0';
			break;
		}
		
		i++;	
	}
	
	if(qr == 0){
		free(mybuf);
		return(NULL);
	}
			
	return mybuf;
}
