#include <iostream>

using namespace std;

int m[12][12];

int main()
{
	int t, n, num, u, v;
	long long  DP[1<<12];
	//long double ans;
	cin>>t;
	while(t--)
	{
		cin>>n>>num;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				m[i][j]=0;
		for(int i=0; i<num; i++)
		{
			cin>>u>>v;
			m[u-1][v-1]=-1;
			m[v-1][u-1]=-1;
			m[u-1][u-1]++;
			m[v-1][v-1]++;
		}
		n--;
		/*
		for(int i=0; i<n; i++)
			for(int j=i+1; j<n; j++)
			{
				long double pivot=m[j][i]/m[i][i];
				for(int k=i; k<n; k++)
					m[j][k]=m[j][k]-pivot*m[i][k];
			}
		ans=1;
		for(int i=0; i<n; i++)
			ans*=m[i][i];
		printf("%Lf\n", ans);
		*/
		DP[0]=1;
		for(int i=1; i<(1<<n); i++)
		{
			DP[i]=0;
			int r=n;
			for(int j=0; j<n; j++)
				r -= (i >> j) & 1;
			int pow=1;
			for(int j=0; j<n; j++)
				if ((i & (1 << j)) != 0)
                        	{
                                	int ind = i ^ (1 << j);
	                                DP[i] +=pow*m[r][j] * DP[ind];
					pow*=-1;
                        	}
		}
		cout<<DP[(1<<n)-1]<<endl;
	}
	return 0;
}
