#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/reg.h>
#include <sys/wait.h>
#include "syscalls.h"
int main(int argc, char *argv[], char *env[])
{
	pid_t child;
	int status, syscall, p;
	struct user_regs_struct regs;
	(void) argc;	
	status = 1;
	syscall = 0;
	p = 0;
	setbuf(stdout, NULL);
	child = fork();
	if (child == 0)
	{
		argv += 1;
		ptrace(PTRACE_TRACEME, child, 0, 0);
		printf("%s", syscalls_64_g[59].name);
        	execve(argv[0], argv, env);
	}
	else
	{
		while(!WIFEXITED(status))
		{
			
			ptrace(PTRACE_SYSCALL, child, NULL, NULL);
			wait(&status);
			ptrace(PTRACE_GETREGS, child, NULL, &regs);
			p = 1;
			if(WIFEXITED(status))
			{
				printf(" = ?\n");
			}
			else if(syscall == 0 && p == 1)
			{
				syscall = 1;
				printf(" = %#lx\n",(size_t) regs.rax);	
			}
			else
			{
				syscall = 0;
				printf("%s", syscalls_64_g[regs.orig_rax].name);
			}
			
		}

	}
	return (0);
}
