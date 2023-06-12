#include <stdio.h>
#include <conio.h>
#define max 25
int main()
{

    int i, j, n, bt[max], wt[max], tat[max];
    float avgwt, avgtat;

    printf("Enter the number of process: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        /* code */
        printf("Enter the Burst Time of %d no process: ", i + 1);
        scanf("%d", &bt[i]);
    }

    printf("Process\t Burst Time \t Waiting Time \t Turn Around Time\n");
    for (i = 0; i < n; i++)
    {
        /* code */
        wt[i] = 0;
        tat[i] = 0;

        for (j = 0; j < i; j++)
        {
            /* code */
            wt[i] = wt[i] + bt[j];
        }
        tat[i] = wt[i] + bt[i];
        avgwt = avgwt + wt[i];
        avgtat = avgtat + tat[i];
        printf("%d \t %d \t %d \t %d \t \n", i + 1, bt[i], wt[i], tat[i]);
    }
    avgwt = avgwt / n;
    avgtat = avgtat / n;
    printf("Average waiting time: %.2f ", avgwt);
    printf("\nAverage turn around time: %.2f ", avgtat);
}