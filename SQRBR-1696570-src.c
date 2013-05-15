#include <stdio.h>

int main()
{
	int t, n, m, i, j;
	char isPresent[38];
	int DP[38][20];
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &n, &m);
		n*=2;
		for(i=0; i<n; i++)
			isPresent[i]=0;
		for(i=0; i<m; i++)
		{
			scanf("%d", &j);
			isPresent[j-1]=1;
		}
		if(isPresent[n-1])
		{
			printf("0\n");
			continue;
		}
		for(j=0; j<=n; j++)
			DP[n-1][j]=0;
		DP[n-1][1]=1;
		for(i=n-2; i>=0; i--)
			for(j=0; j<=n; j++)
			{
				DP[i][j]=0;
				if(isPresent[i])
					DP[i][j]=DP[i+1][j+1];
				else
				{
					if(j<n)
						DP[i][j]+=DP[i+1][j+1];
					if(j>0)
						DP[i][j]+=DP[i+1][j-1];
				}
			}
		printf("%d\n", DP[0][0]);
	}
	return 0;
}
