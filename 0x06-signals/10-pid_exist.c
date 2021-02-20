#include <stdlib.h>
#include <signal.h>
/**
 * pid_exist - Check if pid exist
 * @pid: Process id
 *
 * Return: 1 if exist or -1 otherwise
 */
int pid_exist(pid_t pid)
{
	return (!kill(pid, 0));
}
