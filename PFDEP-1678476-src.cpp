#include <stdio.h>

#define MAX 100
using namespace std;

int main()
{
	int t, n, m, i, j, k, p, d, deg[MAX];
	bool f[MAX][MAX];
	while(1)
	{
		scanf("%d%d", &n, &m);
		for(i=0; i<n; i++)
		{
			deg[i]=0;
			for(j=0; j<n; j++)
				f[i][j]=false;
		}
		for(i=0; i<m; i++)
		{
			scanf("%d%d", &p, &k);
			for(j=0; j<k; j++)
			{
				scanf("%d", &d);
				f[p-1][d-1]=true;
				deg[p-1]++;
			}
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j<n && deg[j]!=0; j++)
				;
			deg[j]=-1;
			if(i==n-1)
				printf("%d\n", j+1);
			else
				printf("%d ", j+1);
			for(k=0; k<n; k++)
				if(f[k][j])
				{
					f[k][j]=false;
					deg[k]--;
				}
		}
		break;
	}
	return 0;
}
