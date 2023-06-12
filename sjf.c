#include <stdbool.h>
#include <stdio.h>
#define max 25


int main()
{
    int i, j, n, bt[max], wt[max], tat[max], temp;
    float avgwt = 0, avgtat = 0;
    bool swapped;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter burst time of process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }


    for (i = 0; i < n; i++)
    {
        /* code */
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (bt[j] > bt[j + 1])
            {
                /* code */
                //swap(&bt[j], bt[j + 1]);
                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;
                swapped = true;
            }
        }
        if (swapped == false)
        {
            /* code */
            break;
        }
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

    return 0;

}