#include <signal.h>
#include <stdio.h>
/**
 * handler - signal handlre
 * @sig: SIGNAL number
 * @si: sigaction
 * @unused: old
 * Return: nothing
 */
static void handler(int sig, siginfo_t *si, void *unused)
{
	(void)unused;
	(void)si;
	printf("Gotcha! [%d]\n", sig);
	fflush(stdout);
}
/**
 * handle_sigaction - set the handler to SIGINT signal
 * Return: 0 on success or -1 otherwise
 */
int handle_sigaction(void)
{
	struct sigaction sa;

	sa.sa_sigaction = handler;
	if (sigaction(SIGINT, &sa, NULL) == -1)
		return (-1);
	return (0);
}
