        ///Shortest Job First (SJF)->Preemptive///
#include<bits/stdc++.h>
using namespace std;

struct Process {
	int pid; // Process ID
	int bt; // Burst Time
	int art; // Arrival Time
};

int wt[100];

void findWaitingTime(Process proc[], int n)
{
	int rt[n];
	for(int i = 0; i < n; i++)
		rt[i] = proc[i].bt;

	int complete = 0, t = 0, minm = INT_MAX;
	int shortest = 0, finish_time;
	bool check = false;

	while(complete != n)
    {
		for (int j = 0; j < n; j++) {
			if ((proc[j].art <= t) &&(rt[j] < minm) && rt[j] > 0)
            {
				minm = rt[j];
				shortest = j;
                int rt[n];

                for (int i = 0; i < n; i++)
                    rt[i] = proc[i].bt;
                check = true;
			}
		}

		if (check == false) {
			t++;
			continue;
		}

		rt[shortest]--;

		minm = rt[shortest];
		if (minm == 0)
			minm = INT_MAX;

		if (rt[shortest] == 0) {

			complete++;
			check = false;

			finish_time = t + 1;

			wt[shortest] = finish_time -
						proc[shortest].bt -
						proc[shortest].art;

			if (wt[shortest] < 0)
				wt[shortest] = 0;
		}
		t++;
	}
}

int main()
{
    freopen("input.txt","r", stdin);
    int n, i, m=0;
    Process p[100];

    scanf("%d", &n);
    for(i=0;i<n;i++){
            scanf("%d", &p[i].bt);
            p[i].pid=i;
            m+=p[i].bt;
    }
    for(i=0;i<n;i++){
            scanf("%d", &p[i].art);
    }
    double avgTime=0.0;
	findWaitingTime(p, n);

	for (int i = 0; i < n; i++)
    {
		avgTime += wt[i];
		printf("PID:%d Burst time: %d   Waiting time: %d\n",  p[i].pid , p[i].bt, wt[i]);
	}
	cout << "\nAverage waiting time = "<< (double)avgTime/n<<endl;
}

