#include <stdio.h>
#define MAX 50

void main()
{
    int i, j, n, t, p[MAX], bt[MAX], at[MAX], wt[MAX], tat[MAX];
    int completed[MAX] = {0}, time = 0, min_bt_index;
    float awt = 0, atat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the process numbers: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    printf("Enter the arrival times of the %d processes:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
    }

    printf("Enter the burst times of the %d processes:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    for (i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;
    }

    int completed_processes = 0;
    while (completed_processes < n)
    {
        min_bt_index = -1;
        int min_bt = 9999;


        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && completed[i] == 0 && bt[i] < min_bt)
            {
                min_bt = bt[i];
                min_bt_index = i;
            }
        }

        if (min_bt_index == -1)
        {

            time++;
            continue;
        }


        wt[min_bt_index] = time - at[min_bt_index];
        tat[min_bt_index] = wt[min_bt_index] + bt[min_bt_index];

        time += bt[min_bt_index];
        completed[min_bt_index] = 1;
        completed_processes++;
    }


    for (i = 0; i < n; i++)
    {
        awt += wt[i];
        atat += tat[i];
    }
    awt /= n;
    atat /= n;


    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i], at[i], bt[i], wt[i], tat[i]);
    }

    printf("Average waiting time = %.2f\n", awt);
    printf("Average turnaround time = %.2f\n", atat);
}
