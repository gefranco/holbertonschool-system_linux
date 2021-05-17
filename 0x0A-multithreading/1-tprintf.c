#include <stdio.h>
#include <stdarg.h>
#include <pthread.h>

/**
 * tprintf - print out a given formatted string
 * @format: format to print
 * Return: 0 on success
 */
int tprintf(char const *format, ...)
{
	printf("[%lu] %s", pthread_self(), format);
	return (0);
}
