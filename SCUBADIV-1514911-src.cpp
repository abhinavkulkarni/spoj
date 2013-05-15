#include <iostream>
#define inf (1<<28)

using namespace std;

struct cyl
{
	int o, nt, wt;
}w[1000];

int DP[1000][80][80];

int main()
{
	int n, t, i, j, o, nt, k, min1;
	cin>>t;
	while(t--)
	{
		cin>>o>>nt>>n;
		for(i=0; i<n; i++)
			cin>>w[i].o>>w[i].nt>>w[i].wt;
		for(i=0; i<80; i++)
			for(j=0; j<80; j++)
				DP[0][i][j]=inf;
		for(k=0; k<n; k++)
			DP[k][0][0]=0;
		DP[0][w[0].o][w[0].nt]=w[0].wt;
		for(k=1; k<n; k++)
			for(i=1; i<80; i++)
				for(j=1; j<80; j++)
				{
					DP[k][i][j]=DP[k-1][i][j];
					if((i-w[k].o>0 && j-w[k].nt>0) || (i-w[k].o==0 && j-w[k].nt==0))
						DP[k][i][j]=min(DP[k][i][j], DP[k-1][i-w[k].o][j-w[k].nt]+w[k].wt);
				}
		min1=inf;
		for(i=o; i<80; i++)
			for(j=nt; j<80; j++)
				if(DP[n-1][i][j]<=min1)
					min1=DP[n-1][i][j];
		cout<<min1<<endl;
	}
	return 0;
}
