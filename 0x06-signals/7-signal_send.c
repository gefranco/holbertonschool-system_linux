#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
/**
 * main - Entry point
 * @argc: args count
 * @argv: arguments
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s <pid>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	if (kill(atoi(argv[1]), SIGINT) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
