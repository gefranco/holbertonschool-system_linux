#include "multithreading.h"
task_t *create_task(task_entry_t entry, void *param)
{
	(void) entry;
	(void) param;
	return (NULL);
}
void destroy_task(task_t *task)
{
	(void) task;
}
void *exec_tasks(list_t const *tasks)
{
	(void) tasks;
	return (NULL);
}
