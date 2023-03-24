// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int wt[20], bt[20], n, tat[20], p[20], i;
    float wtavg, tatavg;
    
    printf("Enter how many process you have:");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("Enter the burst time for %d: ", i+1);
        scanf("%d", &bt[i]);
    }
    
    wt[0] = wtavg = 0;
    tat[0] = tatavg = 0;
    
    for(i=0; i<n; i++)
    {
        wt[i] = tat[i-1];
        tat[i] = bt[i] + wt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }
    
    printf("\n Process \t Burst Time \t Waiting Time \t Turnaround Time");
    for(i=0; i<n;i++)
    {
        printf("\n p%d \t\t %d \t\t\t\t %d \t\t\t\t %d", i+1, bt[i], wt[i], tat[i] );
    }
    printf("\n\n");
    
    printf("Average waiting time ---> %.2f \n", wtavg/n);
    printf("Average turnaround time ---> %.2f ", tatavg/n);
    
}