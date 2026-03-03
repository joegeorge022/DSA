#include <stdio.h>

#define MAX 20
#define INF 9999

typedef struct {
    int pid;
    int arrival;
    int burst;
    int remaining;
    int priority;
    int completion;
    int waiting;
    int finished;
} Process;

void reset(Process p[], Process temp[], int n) {
    for(int i = 0; i < n; i++) {
        p[i] = temp[i];
        p[i].remaining = p[i].burst;
        p[i].finished = 0;
    }
}

float fcfs(Process p[], int n) {
    int time = 0;
    float total_wait = 0;

    for(int i = 0; i < n; i++) {
        if(time < p[i].arrival)
            time = p[i].arrival;

        p[i].waiting = time - p[i].arrival;
        total_wait += p[i].waiting;
        time += p[i].burst;
    }

    return total_wait / n;
}

float srtf(Process p[], int n) {
    int time = 0, completed = 0;
    float total_wait = 0;

    while(completed < n) {
        int min = INF, idx = -1;

        for(int i = 0; i < n; i++) {
            if(p[i].arrival <= time && p[i].remaining > 0) {
                if(p[i].remaining < min) {
                    min = p[i].remaining;
                    idx = i;
                }
            }
        }

        if(idx == -1) {
            time++;
            continue;
        }

        p[idx].remaining--;
        time++;

        if(p[idx].remaining == 0) {
            completed++;
            p[idx].completion = time;
            p[idx].waiting = p[idx].completion - 
                             p[idx].arrival - p[idx].burst;
            total_wait += p[idx].waiting;
        }
    }

    return total_wait / n;
}

float priority_np(Process p[], int n) {
    int time = 0, completed = 0;
    float total_wait = 0;

    while(completed < n) {
        int maxp = -1, idx = -1;

        for(int i = 0; i < n; i++) {
            if(p[i].arrival <= time && p[i].finished == 0) {
                if(p[i].priority > maxp) {
                    maxp = p[i].priority;
                    idx = i;
                }
            }
        }

        if(idx == -1) {
            time++;
            continue;
        }

        p[idx].waiting = time - p[idx].arrival;
        total_wait += p[idx].waiting;
        time += p[idx].burst;
        p[idx].finished = 1;
        completed++;
    }

    return total_wait / n;
}

float round_robin(Process p[], int n, int quantum) {
    int time = 0, completed = 0;
    float total_wait = 0;

    while(completed < n) {
        int done = 1;

        for(int i = 0; i < n; i++) {
            if(p[i].arrival <= time && p[i].remaining > 0) {
                done = 0;

                if(p[i].remaining > quantum) {
                    time += quantum;
                    p[i].remaining -= quantum;
                } else {
                    time += p[i].remaining;
                    p[i].completion = time;
                    p[i].waiting = p[i].completion -
                                   p[i].arrival - p[i].burst;
                    total_wait += p[i].waiting;
                    p[i].remaining = 0;
                    completed++;
                }
            }
        }

        if(done)
            time++;
    }

    return total_wait / n;
}

int main() {
    Process p[MAX], temp[MAX];
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("\nProcess %d\n", i+1);
        p[i].pid = i+1;
        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival);
        printf("Burst Time: ");
        scanf("%d", &p[i].burst);
        printf("Priority: ");
        scanf("%d", &p[i].priority);
        p[i].remaining = p[i].burst;
        temp[i] = p[i];
    }

    float fcfs_wt = fcfs(p, n);
    reset(p, temp, n);

    float srtf_wt = srtf(p, n);
    reset(p, temp, n);

    float prio_wt = priority_np(p, n);
    reset(p, temp, n);

    float rr_wt = round_robin(p, n, 3);

    printf("\nAverage Waiting Times:\n");
    printf("FCFS: %.2f\n", fcfs_wt);
    printf("SRTF: %.2f\n", srtf_wt);
    printf("Priority (Non-Preemptive): %.2f\n", prio_wt);
    printf("Round Robin (q=3): %.2f\n", rr_wt);

    float min = fcfs_wt;
    char best[30] = "FCFS";

    if(srtf_wt < min) { min = srtf_wt; sprintf(best, "SRTF"); }
    if(prio_wt < min) { min = prio_wt; sprintf(best, "Priority"); }
    if(rr_wt < min) { min = rr_wt; sprintf(best, "Round Robin"); }

    printf("\nMinimum Average Waiting Time: %s\n", best);

    return 0;
}