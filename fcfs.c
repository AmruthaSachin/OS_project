#include <stdio.h>
#define MAX 50

void main()
{
    int i, j, n, bt[MAX],at[MAX], wt[MAX], tat[MAX],temp[MAX];
    float awt = 0, atat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the arrival time of the %d processes:",n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
    }


    printf("Enter the burst time of the %d processes:", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }
    temp[0]=0;

    printf("Process\tBurst time\tArrival time\tWaiting time\tTurnaround time\n");
    for(i=0;i<n;i++)
    {
        wt[i]=0;
        tat[i]=0;
        temp[i+1]=temp[i]+bt[i];
        wt[i]=temp[i]-at[i];
        tat[i]=wt[i]+bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i],at[i], wt[i], tat[i]);

    }
       awt /= n;
    atat /= n;

    printf("Average waiting time = %f\n", awt);
    printf("Average turnaround time = %f\n", atat);

}

