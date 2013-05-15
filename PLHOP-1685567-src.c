#include <stdio.h>

long long p[2][50][50];
char c[50][50];
int n;

void per(int m, int idx)
{
	int i, j, k;
	long long min;
	if(m==1)
	{
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				p[idx][i][j]=c[i][j];
		return;
	}
	per(m/2, 1-idx);
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
		{
			p[idx][i][j]=(1<<30);
			p[idx][i][j]*=(1<<30);
			for(k=0; k<n; k++)
				if(p[1-idx][i][k]+p[1-idx][k][j]<p[idx][i][j])
					p[idx][i][j]=p[1-idx][i][k]+p[1-idx][k][j];
		}
	if(m%2)
	{
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				p[1-idx][i][j]=p[idx][i][j];
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
			{
				p[idx][i][j]=(1<<30);
				p[idx][i][j]*=(1<<30);
				for(k=0; k<n; k++)
					if(p[1-idx][i][k]+c[k][j]<p[idx][i][j])
						p[idx][i][j]=p[1-idx][i][k]+c[k][j];
			}
	}
}

int main()
{
	int t, m, i, j, k, test;
	scanf("%d", &t);
	for(test=1; test<=t; test++)
	{
		scanf("%d%d", &m, &n);
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				scanf("%d", &c[i][j]);
		per(m, 0);
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
			{
				p[1][i][j]=(1<<30);
				p[1][i][j]*=(1<<30);
				for(k=0; k<n; k++)
					if(p[1][i][j]>p[0][i][k]+c[k][j])
						p[1][i][j]=p[0][i][k]+c[k][j];
				if(p[1][i][j]>p[0][i][j])
					p[1][i][j]=p[0][i][j];
			}
		printf("Region #%d:\n", test);
		for(i=0; i<n; i++)
		{
			for(j=0; j<n-1; j++)
				printf("%lld ", p[1][i][j]);
			printf("%lld\n", p[1][i][n-1]);
		}
		printf("\n");
	}
	return 0;
}
