#include <signal.h>
#include <stdio.h>
/**
 * handler - signal handlre
 * @num: SIG number
 * Return: nothing
 */
void handler(int num)
{
	printf("Gotcha! [%d]\n", num);
}

int handle_signal(void)
{
	if (signal(SIGINT, handler) == SIG_ERR)
		return (-1);
	return (0);
}
