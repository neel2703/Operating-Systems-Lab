#include <stdlib.h>
#include <stdio.h>
#define N 100005
int n,quantum_time;
struct process
{
    int id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int finishing_time;
    int turn_around_time;
    int remaining_time;
};
struct process P[N];
void RoundRobin()
{
    int complete,current_time,change;
    double total_waiting_time = 0.0;
    double total_turn_around_time = 0.0;
 
    for(int i=0; i<n; i++)
        P[i].remaining_time = P[i].burst_time;
 
    complete = 0;
    current_time = 0;
    printf("\nGNATT CHART\n\n");
    while(complete < n)
    {
        change = 0;
        for(int i=0; i<n; i++)
        {
            if(P[i].arrival_time <= current_time && P[i].remaining_time > 0)
            {
                if(P[i].remaining_time <= quantum_time)
                {
                    complete++;
                    printf("%d TO %d\tPROCESS ID:\t%d\n", current_time, current_time+P[i].remaining_time, P[i].id);
                    current_time += P[i].remaining_time;
 
                    P[i].finishing_time = current_time;
                    P[i].turn_around_time = P[i].finishing_time - P[i].arrival_time;
                    P[i].waiting_time = P[i].turn_around_time - P[i].burst_time;
 
                    total_waiting_time += P[i].waiting_time;
                    total_turn_around_time += P[i].turn_around_time;
 
                    P[i].remaining_time = 0;
                }
                else
                {
                    printf("%d TO %d\tPROCESS ID:\t%d\n",  current_time, current_time+quantum_time, P[i].id);
                    current_time += quantum_time;
                    P[i].remaining_time -= quantum_time;
                }
                change++;
            }
        }
        if(change == 0)
        {
            current_time++;
        }
    }
    printf("\n");
    for(int i=0; i<n; i++)
    {
        printf("PROCESS ID:\t%d\tWAITING TIME:\t%d\tTURNAROUND TIME:\t%d\n", P[i].id, P[i].waiting_time, P[i].turn_around_time);
    }
    printf("\n");
    printf("Average Waiting Time: %0.2f\n",(total_waiting_time/n));
    printf("Average Turn Around Time: %0.2f\n", (total_turn_around_time/n));
    return;
}
int main()
{
    printf("Number of Processes: ");
    scanf("%d", &n);
    printf("Quantum time: ");
    scanf("%d", &quantum_time);
    printf("Process Ids:\n");
    for(int i=0; i<n; i++)
        scanf("%d", &P[i].id);
    printf("Process Burst Times:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &P[i].burst_time);
    } 
    printf("Process Arrival Times:\n");
    for(int i=0; i<n; i++) 
        scanf("%d", &P[i].arrival_time);
    RoundRobin();
    return 0;
}