#include <signal.h>
#include <stdio.h>

/**
 * current_handler_sigaction - set the handler to SIGINT signal
 * Return: current handlres SIGINT or NULL if fail
 */
void (*current_handler_sigaction(void))(int)
{
	struct sigaction sa;

	sa.sa_sigaction = NULL;
	if (sigaction(SIGINT, NULL, &sa) == -1)
		return (NULL);

	return (sa.sa_handler);
}
