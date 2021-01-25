#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
	FILE *f;
	char *buf;
	size_t s = 0;
	char elf_str[300] = {0};
	(void) argc;	
	
	strcat(elf_str, "/usr/bin/readelf -W -h ");
	strcat(elf_str,argv[1]);	

	f = popen(elf_str, "r");
	while( getline(&buf, &s, f) != -1)
		printf("%s", buf);
	return (0);
}
