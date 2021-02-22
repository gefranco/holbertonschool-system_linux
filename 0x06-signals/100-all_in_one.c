#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	printf("Caught: %s\n", strsignal(sig));
	fflush(stdout);
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
	for (i = 1; i < 65; i++)
		sigaction(i, &sa, NULL);
}
