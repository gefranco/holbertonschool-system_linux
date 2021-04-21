#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/reg.h>
#include <sys/wait.h>
#include "syscalls.h"
void print_params(struct user_regs_struct regs);
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
		printf("%s(0, 0, 0)", syscalls_64_g[59].name);
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
				if(regs.orig_rax == 1)
                                        printf(")");
				printf(" = %#lx\n",(size_t) regs.rax);	
			}
			else
			{
				syscall = 0;
				print_params(regs);
				/*printf("%s(%#lx, %#lx, %#lx)",syscalls_64_g[regs.orig_rax].name, (size_t)regs.rdi,(size_t)regs.rsi,(size_t) regs.rdx);*/
			}
			
		}

	}
	return (0);
}

void print_params(struct user_regs_struct regs)
{
	int i = 0;
	size_t params [MAX_PARAMS];
	size_t num_params = syscalls_64_g[regs.orig_rax].nb_params;
	printf("%s(", syscalls_64_g[regs.orig_rax].name);

	for (i = 0; i < num_params; i++)
	{
		if (syscalls_64_g[regs.orig_rax].params[i] == VARARGS)
			printf("...");
		else
		switch (i){
			case 0:
			printf("%#lx", (size_t)regs.rdi);
			break;
			case 1:
			printf("%#lx", (size_t)regs.rsi);
                        break;
			case 2:
                        printf("%#lx", (size_t)regs.rdx);
			break;
			case 3:
                        printf("%#lx", (size_t)regs.rcx);
			break;
			case 4:
                        printf("%#lx", (size_t)regs.r8);
			break;
			case 5:
                        printf("%#lx", (size_t)regs.r9);
			break;
		}		
		if (i < num_params - 1)
			printf(", ");
	}
	if (regs.orig_rax != 1)
		printf(")");
}
