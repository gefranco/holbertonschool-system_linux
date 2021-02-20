#include <signal.h>
#include <stdio.h>
/**
 * current_handler_signal - return a pointer to the handler signal SIGINT
 * Return: nothing
 */
void (*current_handler_signal(void))(int)
{
	void (*handler)(int);

	handler = signal(SIGINT, NULL);
	signal(SIGINT, handler);
	return (handler);
}
