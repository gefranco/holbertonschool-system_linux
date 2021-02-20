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
	(void)sig;
	(void)unused;
	printf("SIGQUIT sent by %ld\n", (long)si->si_pid);
}
/**
 * handle_sigaction - set the handler to SIGINT signal
 * Return: 0 on success or -1 otherwise
 */
int trace_signal_sender(void)
{
	struct sigaction sa;

	sa.sa_sigaction = handler;
	if (sigaction(SIGQUIT, &sa, NULL) == -1)
		return (-1);
	return (0);
}
