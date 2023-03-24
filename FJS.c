// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // Write C code here
   int wt[20], bt[20], n, tat[20], p[20], i,k, temp;
    float wtavg, tatavg;
    
    printf("Enter how many process you have:");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        p[i]=i;
        printf("Enter the burst time for %d: ", i);
        scanf("%d", &bt[i]);
    }
    for(i=0; i<n; i++)
    {
        for(k = i +1 ; k<n ; k++)
        {
            if(bt[i]> bt[k])
            {
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;
                
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }
        }
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
        printf("\n p%d \t\t %d \t\t\t\t %d \t\t\t\t %d", p[i], bt[i], wt[i], tat[i] );
    }
    printf("\n\n");
    
    printf("Average waiting time ---> %.2f \n", wtavg/n);
    printf("Average turnaround time ---> %.2f ", tatavg/n);
}