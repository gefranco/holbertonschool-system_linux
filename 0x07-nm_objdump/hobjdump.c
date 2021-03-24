#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	char *av[] = {"./hobjdump", "-sf", "", NULL};

	(void) argc;

	av[2] = argv[1];

	if (execve("/usr/bin/objdump", av, NULL) == -1)
	{
		perror("execve");
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
