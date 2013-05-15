#include <stdio.h>

int main()
{
	int t, n, k, l, i, num, d, r, pow10, pow;
	long long DP[20][999];
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &n, &k);
		for(l=0; l<=k; l++)
			for(r=0; r<n; r++)
				DP[l][r]=0;
		for(i=1; i<10; i++)
			DP[1][i%n]++;
		for(i=11; i<=99; i+=11)
			DP[2][i%n]++;
		for(l=3, pow10=100%n; l<=k; l++, pow10=(10*pow10)%n)
		{
			for(r=0; r<n; r++)
				for(d=1; d<10; d++)
				{
					for(num=0, pow=10%n; num<(l+1)/2-1; num++, pow=(pow*10)%n)
						DP[l][(d*pow10+r*pow+d)%n]+=DP[l-2*(num+1)][r];
				}
			for(d=1; d<10; d++)
				DP[l][(d*pow10+d)%n]++;
		}
		printf("%lld\n", DP[k][0]);
	}
	return 0;
}
