#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
int main()
{
        pid_t pid=fork();
        if(pid==0)
        {
                printf("HELLO FROM CHILD!!! :)\n");
        }
        else
        {
                wait(NULL);
                printf("I AM PARENT WAITING FOR CHILD :(\n");
        }
        return 0;
}
