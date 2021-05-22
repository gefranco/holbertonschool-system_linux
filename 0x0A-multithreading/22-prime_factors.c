#include "multithreading.h"
#include <stdlib.h>
#include <pthread.h>


task_t *create_task(task_entry_t entry, void *param)
{
	task_t *task = malloc(sizeof(task_t));
	
	if (task)
	{
		task->entry = entry;
		task->param = param;
		task->lock = task_mutex;
		task->status = PENDING;
		task->result = NULL;
	}
	
	return (task);
}
void destroy_task(task_t *task)
{
	if(task)
	{
		list_destroy(task->result, free);
		free(task->result);
		free(task);
	}

}
void *exec_tasks(list_t const *tasks)
{
	node_t *node;
	int i = 0;
	if (!tasks)
		pthread_exit(NULL);
	
	
	while(1)
	{
		for (node = tasks->head; node; node = node->next, i +=1)
		{
			if (((task_t *)(node->content))->status == PENDING)
			{
				((task_t *)(node->content))->status = STARTED;
				tprintf("[%02d] Started\n", i);
				
				((task_t *)(node->content))->result = 
							((task_t *)(node->content))->
								entry(((task_t *)(node->content))->param);
				if(((task_t *)(node->content))->result)
				{
					((task_t *)(node->content))->status = SUCCESS;
					tprintf("[%02d] Success\n", i);
				}
			
				else
				{
					((task_t *)(node->content))->status = FAILURE;
					tprintf("[%02d] Failure\n", NULL);
				}
			}
		}
		break;
	}
	
	return (NULL);	
}
