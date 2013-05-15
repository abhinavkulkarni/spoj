#include <iostream>

using namespace std;

char a[1000][1000];
int h[1000][1000], l[1000][1000], r[1000][1000];

int main()
{
	int t, n, m, area;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				cin>>a[i][j];
		for(int j=0; j<m; j++)
			h[0][j]=(a[0][j]=='F');
		for(int i=0; i<n; i++)
			l[i][0]=0;
		for(int i=0; i<n; i++)
			r[i][m-1]=0;
		for(int i=1; i<n; i++)
			for(int j=0; j<m; j++)
				if(a[i][j]=='R')
					h[i][j]=0;
				else
					h[i][j]=h[i-1][j]+1;
		for(int i=0; i<n; i++)
			for(int j=1; j<m; j++)
				if(a[i][j]=='R' || h[i][j-1]<h[i][j])
					l[i][j]=0;
				else
					l[i][j]=l[i][j-1]+1;
		for(int i=0; i<n; i++)
			for(int j=m-2; j>=0; j--)
				if(a[i][j]=='R' || h[i][j+1]<h[i][j])
					r[i][j]=0;
				else
					r[i][j]=r[i][j+1]+1;
		area=0;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				area=max(area, h[i][j]*(l[i][j]+r[i][j]+1));
		cout<<3*area<<endl;
	}
	return 0;
}
