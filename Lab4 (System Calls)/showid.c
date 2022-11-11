#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
int main()
{
        printf("IN PARENT PROCESS\n");
        printf("PROCESS ID: %d\n", getpid());
        printf("PARENT PROCESS ID: %d\n", getppid());
        pid_t pid=fork();
        if(pid==0)
        {
                printf("IN CHILD PROCESS\n");
                printf("PROCESS ID: %d\n", getpid());
                printf("PARENT PROCESS ID: %d\n", getppid());
        }
        else
        {
                wait(NULL);
                printf("HELLO AGAIN FROM PARENT PROCESS: \n");
                printf("PROCESS ID: %d\n", getpid());
                printf("PARENT PROCESS ID: %d\n", getppid());
        }
        return 0;
}