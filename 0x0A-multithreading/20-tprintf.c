#include <stdio.h>
#include <stdarg.h>
#include <pthread.h>
#include "multithreading.h"


pthread_mutex_t lock;
/**
 * tprintf - print out a given formatted string
 * @format: format to print
 * Return: 0 on success
 */
int tprintf(char const *format, ...)
{

	pthread_mutex_lock(&lock);
		printf("[%lu] %s", pthread_self());
		vprintf(format, arguments);
	pthread_mutex_unlock(&lock);
	return (0);
}
/**
 * begin - constructor
 */
void begin(void)
{
	pthread_mutex_init(&lock, NULL);
}
/**
 * end - destructor
 */
void end(void)
{
	pthread_mutex_destroy(&lock);
}

