#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
int main()
{
        printf("ONLY PARENT PROCESS CREATED TILL NOW\n");
        printf("Parent PID: %d\n", getpid());
        pid_t pid=fork();
        if(pid==0)
        {
                printf("IN CHILD PROCESS \n");
                printf("Current PID: %d\nCurrent Parent PID: %d\n", getpid(), getppid());
                sleep(3);
                printf("PARENT PROCESS PROBABLY DEAD NOW\n");
                printf("Current PID: %d\nCurrent Parent PID: %d\n", getpid(), getppid());
        }
        else
        {
                sleep(1);
                printf("IN PARENT PROCESS\n");
                printf("Current PID: %d\n", getpid());
        }
        return 0;
}
~      