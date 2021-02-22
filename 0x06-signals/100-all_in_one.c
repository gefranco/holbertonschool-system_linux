#include <signal.h>
#include <stdlib.h>
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
	(void)sig;
	psiginfo(si, "Caught");
}
/**
 * all_in_one - set the handler to ALL signals
 * Return: nothing
 */
void all_in_one(void)
{
	struct sigaction sa;
	int i;

	sa.sa_sigaction = handler;
	for (i = 1; i <= SIGRTMAX; i++)
		sigaction(i, &sa, NULL);
}
