#include "multithreading.h"
#include <stdio.h>
#include <pthread.h>
/**
 * thread_entry -  entry point to a new thread
 * @arg: holds the address of a string that must be printed
 * Return: nothing
 */
void *thread_entry(void *arg)
{

	char *str = (char *)arg;

	printf("%s\n", str);
	pthread_exit(NULL);
}
