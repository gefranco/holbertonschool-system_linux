#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * handler - signal handlre
 * @num: SIG number
 * Return: nothing
 */
void handler(int num)
{
	printf("Caught %d\n", num);
}

/**
 * handle_signal - set the handler to SIGINT signal
 * Return: 0 on success or -1 otherwise
 */
int handle_signal(void)
{

	if (signal(SIGINT, handler) == SIG_ERR)
		return (-1);
	return (0);
}

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{

	handle_signal();
	pause();

	printf("Signal received\n");
	return (EXIT_SUCCESS);
}
