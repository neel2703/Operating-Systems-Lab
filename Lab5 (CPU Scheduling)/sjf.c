#include<stdio.h>
void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int waitingtime(int proc[], int n, int burst_time[], int wait_time[]) 
{
   wait_time[0] = 0;
   for (int i = 1; i < n ; i++ )
        wait_time[i] = burst_time[i-1] + wait_time[i-1] ;
   return 0;
}
int turnaroundtime( int proc[], int n, int burst_time[], int wait_time[], int tat[]) 
{
    int i;
   for ( i = 0; i < n ; i++)
   tat[i] = burst_time[i] + wait_time[i];
   return 0;
}
void chart(int proc[], int burst_time[], int n)
{
    int i, t;
    print("\nGNATT CHART: \n\n")
    for(i=0; i<n; i++)
    {
        if(i==0)
        {
            printf("%d to %d:\tPROCESS %d\n", 0, burst_time[i], proc[i]);
            t=burst_time[i];
        }
        else
        {
            printf("%d to %d:\tPROCESS %d\n", t, t+burst_time[i], proc[i]);
            t=t+burst_time[i];
        }
    }
}
int avgtime( int proc[], int n, int burst_time[]) 
{
   int wait_time[n], tat[n], total_wt = 0, total_tat = 0;
   int i;
   chart(proc, burst_time, n);
   waitingtime(proc, n, burst_time, wait_time);
   turnaroundtime(proc, n, burst_time, wait_time, tat);
   printf("Processes  Burst   Waiting Turn around \n");
   for ( i=0; i<n; i++) {
      total_wt = total_wt + wait_time[i];
      total_tat = total_tat + tat[i];
      printf(" %d\t  %d\t\t %d \t%d\n", proc[i], burst_time[i], wait_time[i], tat[i]);
   }
   printf("Average waiting time = %f\n", (float)total_wt / (float)n);
   printf("Average turn around time = %f\n", (float)total_tat / (float)n);
   return 0;
}
void selectionSort(int array[], int a2[], int size) 
{
    for (int step = 0; step < size - 1; step++) 
    {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) 
        {
            if (array[i] < array[min_idx])
                min_idx = i;
        }
        swap(&array[min_idx], &array[step]);
        swap(&a2[min_idx], &a2[step]);
       }
}
int main() 
{
   int proc[50], burst_time[50], n;
   printf("Enter no of processes: ");
   scanf("%d", &n);
   for(int i=0; i<n; i++)
   {
        printf("Enter burst time for Process %d :\t", i+1, &burst_time[i]);
        proc[i]=i+1;
        scanf("%d", &burst_time[i]);
   }
   selectionSort(burst_time, proc, n);
   avgtime(proc, n, burst_time);
   return 0;
}