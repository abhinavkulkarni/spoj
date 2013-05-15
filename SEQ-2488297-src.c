#include <stdio.h>

long long MOD=1000000000, b[10], c[10][10], a[2][10][10], n;
int k;

void power(long long p, int idx)
{
	int i, j, l;
	if(p==1)
	{
		for(i=0; i<k; i++)
			for(j=0; j<k; j++)
				a[idx][i][j]=c[i][j];
		return;
	}
	power(p/2, 1-idx);
	for(i=0; i<k; i++)
		for(j=0; j<k; j++)
		{
			a[idx][i][j]=0;
			for(l=0; l<k; l++)
				a[idx][i][j]=(a[idx][i][j]+a[1-idx][i][l]*a[1-idx][l][j])%MOD;
		}
	if(p%2==0)
		return;
	for(i=0; i<k; i++)
		for(j=0; j<k; j++)
			a[1-idx][i][j]=a[idx][i][j];
	for(i=0; i<k; i++)
		for(j=0; j<k; j++)
		{
			a[idx][i][j]=0;
			for(l=0; l<k; l++)
				a[idx][i][j]=(a[idx][i][j]+a[1-idx][i][l]*c[l][j])%MOD;
		}
	return;
}

int main()
{
	int t, i, j;
	long long ans;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &k);
		for(i=0; i<k; i++)
			scanf("%lld", &b[i]);
		for(i=0; i<k; i++)
			scanf("%lld", &c[0][i]);
		for(i=1; i<k; i++)
		{
			for(j=0; j<k; j++)
				c[i][j]=0;
			c[i][i-1]=1;
		}
		scanf("%lld", &n);
		if(n<=k)
		{
			printf("%lld\n", b[n-1]);
			continue;
		}
		power(n-k, 0);
		ans=0;
		for(i=0; i<k; i++)
			ans=(ans+a[0][0][i]*b[k-i-1])%MOD;
		printf("%lld\n", ans);
	}
	return 0;
}
