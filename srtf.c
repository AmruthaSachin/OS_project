#include <stdio.h>

struct Process
{
    int pid;
    int bt;
    int at;
    int rt;
    int wt;
    int tat;
};

void findWaitingAndTurnaroundTime(struct Process proc[], int n)
{
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++)
    {
        proc[i].tat = proc[i].wt + proc[i].bt;
        total_wt += proc[i].wt;
        total_tat += proc[i].tat;
    }

    printf("\nProcess ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].bt, proc[i].at, proc[i].wt, proc[i].tat);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat / n);
}

void srtf(struct Process proc[], int n)
{
    int time = 0;
    int completed = 0;
    int min_index;

    for (int i = 0; i < n; i++)
    {
        proc[i].rt = proc[i].bt;
    }

    while (completed < n)
    {
        min_index = -1;
        int min_rt = 9999;

        for (int i = 0; i < n; i++)
        {
            if (proc[i].at <= time && proc[i].rt > 0 && proc[i].rt < min_rt)
            {
                min_rt = proc[i].rt;
                min_index = i;
            }
        }

        if (min_index == -1)
        {
            time++;
            continue;
        }

        proc[min_index].rt--;
        time++;

        if (proc[min_index].rt == 0)
        {
            proc[min_index].wt = time - proc[min_index].at - proc[min_index].bt;
            completed++;
        }
    }

    findWaitingAndTurnaroundTime(proc, n);
}

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Process ID, Arrival Time, and Burst Time for Process %d: ", i + 1);
        scanf("%d %d %d", &proc[i].pid, &proc[i].at, &proc[i].bt);
    }

    srtf(proc, n);

    return 0;
}
