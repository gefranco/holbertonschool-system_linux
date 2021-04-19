#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/reg.h>
#include <sys/wait.h>
int main(int argc, char *argv[], char *env[])
{
	pid_t child;
	long orig_eax;
	int status;
	(void) argc;	
	child = fork();
	if (child == 0)
	{
		argv += 1;
		ptrace(PTRACE_TRACEME, 0, 0, 0);
        	return execve(argv[0], argv, env);
	}
	else
	{
		while(1)
		{
	
			wait(&status);
			if(WIFEXITED(status))
				break;
			orig_eax = ptrace(PTRACE_PEEKUSER, child, sizeof(long) * ORIG_RAX);
			if (orig_eax == -1)
				break;
			fprintf(stdout,"%ld\n", orig_eax);
			ptrace(PTRACE_SYSCALL, child, 0, 0);
		}
	}
	return 0;
}
