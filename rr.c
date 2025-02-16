#include<stdio.h>
void main()
{
    int n, i, qt, count = 0, temp, sq = 0, bt[10], wt[10], tat[10], rem_bt[10];
    float awt = 0, atat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time of each process: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }

    printf("Enter the quantum time: ");
    scanf("%d", &qt);

    while (1)
    {
        for (i = 0, count = 0; i < n; i++)
        {
            temp = qt;
            if (rem_bt[i] == 0)
            {
                count++;
                continue;
            }
            if (rem_bt[i] > qt)
            {
                rem_bt[i] = rem_bt[i] - qt;
            }
            else
            {
                temp = rem_bt[i];
                rem_bt[i] = 0;
            }
            sq = sq + temp;
            tat[i] = sq;
        }

        if (n == count)
            break;
    }

    printf("\nProcess\tBurst time\tTurnaround time\tWaiting time\n");
    for (i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        printf("\n%d\t%d\t\t%d\t\t%d", i + 1, bt[i], tat[i], wt[i]);
    }

    awt /= n;
    atat /= n;

    printf("\nAverage waiting time = %f\n", awt);
    printf("Average turnaround time = %f\n", atat);
}

