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
	int status, syscall;
	struct user_regs_struct regs;
	(void) argc;	
	status = 1;
	syscall = 0;
	setbuf(stdout, NULL);
	child = fork();
	if (child == 0)
	{
		argv += 1;
		ptrace(PTRACE_TRACEME, child, 0, 0);
        	execve(argv[0], argv, env);
	}
	else
	{
		while(!WIFEXITED(status))
		{
			
			ptrace(PTRACE_SYSCALL, child, NULL, NULL);
			wait(&status);
			ptrace(PTRACE_GETREGS, child, NULL, &regs);
			if(syscall == 0)
			{
				syscall = 1;			
			}
			else
			{
				syscall = 0;
				printf("%ld\n",(size_t) regs.orig_rax);
			}
			
		}

	}
	return (0);
}
