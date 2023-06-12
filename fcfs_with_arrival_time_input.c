#include<stdio.h>
#define max 25

int main() {
    int i, j, n, bt[max], at[max], wt[max], tat[max], temp[max];
    float avgwt=0, avgtat=0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter burst time of process %d: ", i+1);
        scanf("%d", &bt[i]);
    }

    for (i = 0; i < n; i++) {
        printf("\nEnter arrival time of process %d: ", i+1);
        scanf("%d", &at[i]);
    }

    printf("\nProcess No \t Burst Time \t Arrival Time \t Waiting Time \t Turn Around Time\n");

    temp[0] = 0; // Initialize the first element of temp array

    for (i = 0; i < n; i++) {
        wt[i] = 0;
        tat[i] = 0;

        temp[i+1] = temp[i] + bt[i];
        wt[i] = temp[i] - at[i];
        tat[i] = wt[i] + bt[i];
        avgwt = avgwt + wt[i];
        avgtat = avgtat + tat[i];
        printf("%d \t\t %d \t\t %d \t\t %d \t\t %d\n", i+1, bt[i], at[i], wt[i], tat[i]);
    }

    avgwt = avgwt/n;
    avgtat = avgtat/n;

    printf("Average waiting time: %.2f\n", avgwt);
    printf("Average turn around time: %.2f\n", avgtat);

    return 0;
}
