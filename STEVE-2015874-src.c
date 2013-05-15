#include <stdio.h>

#define min(a, b) (a<b ? a : b)
#define max(a, b) (a>b ? a : b)
#define inf (1<<28)

int main()
{
	int t, num, n, m, i, j, k, l, total, res;
	int DP[101][101][101];
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &num, &k);
		
		DP[0][0][0]=0;
		DP[1][0][0]=1;
		DP[1][1][0]=1;

		for(n=2; n<=num; n++)
		{
			for(l=0; l<=n; l++)
				DP[n][l][n-l]=DP[l][0][0];
			for(total=n-1; total>=0; total--)
				for(l=0; l<=total; l++)
				{
					m=total-l;
					res=0;
					if(n-l-m<=k)
						res=n-m+(m-DP[m][0][0]);
					if(n-l-m<2)
						goto label;
					for(i=1; i<=min(n-l-m-1, k); i++)
					{
						int ans=inf;
						for(j=1; j<=min(n-l-i-m, k); j++)
							ans=min(ans, DP[n][l+i][m+j]);
						res=max(res, ans);
					}
				label:
					DP[n][l][m]=res;	
				}
		}
		printf("%d\n", DP[num][0][0]);
	}
	return 0;
}
