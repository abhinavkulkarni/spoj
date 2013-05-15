#include <stdio.h>

int DP[221][11][221];

int main()
{
	int test, m, n, k, x, num;
	scanf("%d", &test);
	for(m=0; m<=220; m++)
		for(n=0; n<=10; n++)
			for(k=0; k<=m; k++)
				DP[m][n][k]=0;
	for(m=1; m<=220; m++)
		DP[m][1][m]=1;
	for(m=1; m<=220; m++)
		for(n=2; n<=10; n++)
			for(k=1; n*k<=m; k++)
				for(x=k; x<=(m-k)/(n-1); x++)
					DP[m][n][k]+=DP[m-k][n-1][x];
	while(test--)
	{
		scanf("%d%d%d", &m, &n, &num);
		x=1;
		num--;
		while(n)
		{
			for(; num>=0; x++)
				num-=DP[m][n][x];
			num+=DP[m][n][--x];
			if(n>1)
				printf("%d ", x);
			else
				printf("%d\n", x);
			m-=x;
			n--;
		}
	}
	return 0;
}
