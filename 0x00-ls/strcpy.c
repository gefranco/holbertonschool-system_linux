#include "hls.h"

int _strcpy(char *s, int i, char *d)
{
	
	
	int j;

	for (j = 0; j < _strlen(s); j++)
	{
		d[j] = s[j+i];	
	}
	return (0);
}
