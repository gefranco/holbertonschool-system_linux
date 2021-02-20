#include <signal.h>
#include <stdio.h>
/**
 * handler - signal handlre
 * @num: SIG number
 * Return: nothing
 */
void handler(int num)
{
	fprintf(stdout, "Gotcha! [%d]\n", num);
	fflush(stdout);
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
