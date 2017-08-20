#include <bits/stdc++.h>

using namespace std;

struct Process{
    int pid,bt,at;
};

const int MAXN = 100001;

int process_count;
int wt[MAXN];

void SJFpx(Process* proc)
{
    int t = 1,minm = INT_MAX,complete = 0;
    int shortest = -1;
    int arr[process_count];
    for(int i = 0;i < process_count;++i)
        arr[i] = proc[i].bt;
    while(complete != process_count)
    {
        // printf("%d\n",complete);
        for(int i = 0;i < process_count;++i)
        {
            // printf("%d %d\n",proc[i].at,proc[i].bt);
            // printf("%d %d\n",t,minm);
            if(proc[i].at <= t && proc[i].bt < minm && proc[i].bt > 0)
            {
                shortest = i;
                minm = proc[i].bt;
            }
        }
        // printf("%d\n",shortest);
        if(shortest == -1)
        {
            t++;
            continue;
        }
        minm = proc[shortest].bt;
        proc[shortest].bt  = max(0,proc[shortest].bt - 1);
        if(proc[shortest].bt == 0)
        {
            wt[shortest] = max(0,t - arr[shortest] - proc[shortest].at + 1);
            complete++;
            minm = INT_MAX,shortest = -1;
        }
        t++;
    }
    for(int i = 0;i < process_count;++i)
        proc[i].bt = arr[i];
}

double findAvgWaitTime()
{
    if(process_count == 0)
        return 0;
    int sum = 0;
    for(int i = 0;i < process_count;++i)
        sum += wt[i];
    return (1.0*sum)/(1.0*process_count);
}

double findAvgTurnAroundTime(Process* proc)
{
    if(process_count == 0)
        return 0;
    int sum = 0;
    for(int i = 0;i < process_count;++i)
        sum += wt[i] + proc[i].bt;
    return (1.0*sum)/(1.0*process_count);
}

int main()
{
    Process proc[] = {
        { 1, 6, 1 },
        { 2, 8, 1 },
        { 3, 7, 2 },
        { 4, 3, 3 }
    };
    process_count = 4;
    // memset(wt,0,sizeof(wt));
    SJFpx(proc);
    cout << findAvgWaitTime() << '\n';
    cout << findAvgTurnAroundTime(proc) << '\n';

    return 0;
}