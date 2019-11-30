        ///Shortest Job First(SJF)->NonPreemptive///
#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
int main()
{
    freopen("input.txt","r", stdin);
    int n, i, burstTime[100];
    double avgTime=0.0;
    priority_queue<pii, vector<pii>, greater<pii> >q;
    scanf("%d", &n);
    for(i=0;i<n;i++){
            scanf("%d", &burstTime[i]);
            q.push({burstTime[i], i});
    }
    int Time=0, id, prev=0;
    while(!q.empty())
    {
            avgTime+=Time;
            Time+=q.top().first;
            printf("PID:%d starting: %d   Finishing: %d\n", q.top().second, prev,Time);
            prev=Time;
            q.pop();
    }
    cout<<endl<<"Average Waiting Time: "<<avgTime/n<<endl;
    return 0;
}
