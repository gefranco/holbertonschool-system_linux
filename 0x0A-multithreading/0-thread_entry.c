#include "multithreading.h"
#include <stdio.h>
#include <pthread.h>
void *thread_entry(void *arg)
{
	char *str = (char *)arg;
	printf("%s\n", str);
	pthread_exit(NULL);
}
