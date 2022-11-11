#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
    int arr[50], n;
    printf("Enter no of elements in the array: \n");
    scanf("%d", &n);
    printf("Enter the array elements one by one: \n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    pid_t pid=fork();
    if(pid==0)
    {
        qsort(arr, n, sizeof(int), cmpfunc);
        printf("The SORTED array is: \n");
        for(int i=0; i<n; i++)
        {
            printf("%d  ", arr[i]);
        }
        printf("\nTHIS WAS THE CHILD PROCESS!!!!\n");
    }
    else
    {
        wait(NULL);
        printf("The UNSORTED array is: \n");
        for(int i=0; i<n; i++)
        {
            printf("%d  ", arr[i]);
        }
        printf("\nTHIS WAS THE PARENT PROCESS\n");
    }
}