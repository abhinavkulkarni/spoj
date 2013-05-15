#include <iostream>

using namespace std;

int main()
{
	int t, w, h, n, W, H;
	int DP[601][601];
	cin>>t;
	while(t--)
	{
		cin>>W>>H>>n;
		for(int i=0; i<=W; i++)
			for(int j=0; j<=H; j++)
				DP[i][j]=i*j;
		for(int i=0; i<n; i++)
		{
			cin>>w>>h;
			DP[w][h]=0;
		}
		for(int i=0; i<=W; i++)
			for(int j=0; j<=H; j++)
			{
				if(DP[i][j]==0)
					continue;
				for(int k=1; k<i; k++)
					DP[i][j]=min(DP[i][j], DP[k][j]+DP[i-k][j]);
				for(int k=1; k<j; k++)
					DP[i][j]=min(DP[i][j], DP[i][k]+DP[i][j-k]);
			}
		cout<<DP[W][H]<<endl;
	}
	return 0;
}
