#include<stdlib.h>
#include<stdio.h>
void sort(int ari[], int bur[], int n)
{ 
    int i, j, temp;
    for(i=0; i<n; i++)
    {
        for (j = i + 1; j < n; j++) 
        { 
            if (ari[i] > ari[j]) 
            { 
                temp = ari[i]; 
                ari[i] = ari[j]; 
                ari[j] = temp; 
                temp = bur[i]; 
                bur[i] = bur[j]; 
                bur[j] = temp; 
 
            } 
        }
    } 
}
void process(int bur[], int ari[], int n, int procs[], int total)
{
    int i, temp, k, j, small;
    for(i=0; i<n; i++)
    for (i = 0; i < total; i++)                                                   //which process executing at which second
    { 
        small = __INT_MAX__; 
        for (j = 0; j < n; j++) 
        { 
            if ((bur[j] != 0) && (ari[j] <= i) && (bur[j] < small))              //finding smallest unexecuted process
            { 
                small = bur[j]; 
                k = j; 
            } 
        } 
        bur[k]--; 
        procs[i] = k; 
    }
    printf("\nGNATT CHART: \n\n");
    for(i=0; i<total; )
    {
        temp=procs[i];
        printf("%d to ", i);
        while(procs[i]==temp && i<total)
        {
            i++;
        }
        printf("%d\t\t PROCESS %d\n", i, temp+1);
    }
    int wt, tat;
}
float waitingtime(int procs[], int n, int total, int ari[])
{
    int finish[n], waiting[n], i, j;
    for(i=0; i<n; i++)
    {
        waiting[i]=0;
    }
    float wavg=0;
    for (i = 0; i < total; i++) 
    { 
        for (j = 0; j < n; j++) 
        { 
            if (procs[i] == j)  
            { 
                finish[j] = i; 
                waiting[j]++; 
            } 
        } 
    }
    for (i = 0; i < n; i++) 
    { 
        printf("\nPROCESS:   %d\tWAITING TIME:   %d\n", i + 1,  (((finish[i] + 1) - waiting[i]) - ari[i])); 
        wavg = wavg + (((finish[i] + 1) - waiting[i]) - ari[i]);  
    }
    return wavg/n;
}
float turnaroundtime(int procs[], int n, int total, int ari[])
{
    int finish[n], i, j;
    float tavg=0;
    for (i = 0; i < total; i++) 
    { 
        for (j = 0; j < n; j++) 
        { 
            if (procs[i] == j)  
            { 
                finish[j] = i;
            } 
        } 
    }
    for (i = 0; i < n; i++) 
    { 
            printf("\n PROCESS:   %d\tTURNAROUND TIME:   %d\n", i + 1,(finish[i] - ari[i]) + 1 );  
            tavg = tavg + ((finish[i] - ari[i]) + 1); 
    }
    return tavg/n;
}
int main()
{
    int n, ari[10], bur[10], total = 0, i, j, small, temp, procs[100], k, waiting[10], finish[10]; 
    float tavg = 0.0, wavg = 0.0; 
    printf("ENTER THE NUMBER OF PROCESSES:"); 
    scanf("%d", & n);                                  //n is the number of processes
    for (i = 0; i < n; i++) 
    {
        printf("ENTER THE ARRIVAL TIME OF PROCESS %d:\t", i+1); 
        scanf("%d", & ari[i]); 
        printf("ENTER THE BURST TIME OF PROCESS %d:\t", i+1); 
        scanf("%d", & bur[i]); 
        waiting[i] = 0;
        total=total+bur[i];
    } 
    sort(ari, bur, n);
    process(bur, ari, n, procs, total);
    float wt, tat;
    wt=waitingtime(procs, n, total, ari);
    printf("AVERAGE WAITING TIME:\t\n%0.2f", wt);
    tat=turnaroundtime(procs, n, total, ari);
    printf("AVERAGE TURNAROUND TIME:\t\n%0.2f", tat);
}
