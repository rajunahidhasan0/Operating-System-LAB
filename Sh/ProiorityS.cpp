
#include <bits/stdc++.h>
#define P(X) cout<<"db "<<X<<endl;
#define P2(X,Y) cout<<"d2 "<<X<<" "<<Y<<endl;
#define ll long long
#define rep(i,n) for(i=1;i<=n;i++)
#define FO freopen("t.txt","w",stdout);
#define MS(XX,YY) memset(XX,YY,sizeof(XX));
#define pii pair<int,int>
#define FastIO ios_base::sync_with_stdio(0);cin.tie(nullptr);
using namespace std;
int btime[200];
struct process{
    int pid,bstime,prio;
    bool operator < (const process&x){
        //if(x.prio==prio) return bstime < x.bstime;
         return prio < x.prio;
    }
} plist[200];
int main()
{
    int i,j,a,b,ts,cn=0,x,n,wtime=0,curtime=0,ftime=0,stm=0,pr;
    double avgwt=0,avgft=0;
    freopen("test.txt","r",stdin);
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d",&x,&pr);
        plist[i-1].bstime=x;
        plist[i-1].pid=i;
        plist[i-1].prio=pr;
    }
    sort(plist,plist+n);
    for(i=0;i<n;i++){
        wtime+=curtime;
        stm=curtime;
        curtime+=plist[i].bstime;
        //(plist[i].bstime)
        ftime+=curtime;

        printf("PID: %d Starting: %d, Finishing: %d\n",plist[i].pid,stm,curtime);
        //curtime++;
    }

    avgwt=(double)wtime/n;
    avgft=(double)ftime/n;

    printf("Average waiting time: %.2lf\n",avgwt);
    printf("Average Finishing time: %.2lf\n",avgft);

    return 0;
}

