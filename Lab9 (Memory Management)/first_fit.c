#include <stdio.h>

void implimentFirstFit(int blockSize[], int blocks, int processSize[], int processes)
{
    int allocate[processes];
    int occupied[blocks];
    for(int i = 0; i < processes; i++)
        {
                allocate[i] = -1;
        }

        for(int i = 0; i < blocks; i++){
        occupied[i] = 0;
    }
    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < blocks; j++)
        {
        if (!occupied[j] && blockSize[j] >= processSize[i])
            {
                allocate[i] = j;
                occupied[j] = 1;

                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < processes; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
        if (allocate[i] != -1)
            printf("%d\n",allocate[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main()
{
    int blockSize[] = {100,500,200,300,600};
    int processSize[] = {212,417,112,426};
    int m = sizeof(blockSize)/sizeof(blockSize[0]);
    int n = sizeof(processSize)/sizeof(processSize[0]);

    implimentFirstFit(blockSize, m, processSize, n);
    return 0;
}