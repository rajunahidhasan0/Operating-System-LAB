        ///First Come First Serve(FCFS)///
#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
int main()
{
    freopen("input.txt","r", stdin);
    int n, i, burstTime[100];
    double avgTime=0.0;
    queue<pii>q;
    scanf("%d", &n);
    for(i=0;i<n;i++){
            scanf("%d", &burstTime[i]);
            q.push({i,burstTime[i]});
    }
    int Time=0, id, prev=0;
    //cout<<Time<<" ";
    while(!q.empty())
    {
            avgTime+=Time;
            Time+=q.front().second;
            //cout<<Time<<" ";
            printf("PID:%d starting: %d   Finishing: %d\n", q.front().first, prev,Time);
            prev=Time;
            q.pop();
    }
    cout<<endl<<"Average Waiting Time: "<<avgTime/n<<endl;
    return 0;
}
