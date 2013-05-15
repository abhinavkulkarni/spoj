#include <stdio.h>

int main()
{
	int n, idx, a[9000], i, t, left, right, tmax, sum[9001];
	while(1)
	{
		scanf("%d", &n);
		if(!(n+1))
			break;
		sum[0]=0;
		for(i=0; i<n; i++)
		{
			scanf("%d", &a[i]);
			sum[i+1]=sum[i]+a[i];
		}
		if(sum[n]%n)
		{
			printf("-1\n");
			continue;
		}
		tmax=0;
		for(i=0; i<n; i++)
			if(a[i]>sum[n]/n)
			{
				left=sum[i];
				right=sum[n]-sum[i+1];
				if(left<(sum[n]/n)*i)
					left=(sum[n]/n)*i-left;
				else
					left=0;
				if(right<(sum[n]/n)*(n-i-1))
					right=(sum[n]/n)*(n-i-1)-right;
				else
					right=0;
				if(left>right)
					t=left;
				else
					t=right;
				tmax=tmax<t ? t : tmax;
			}
		printf("%d\n", tmax);
	}
	return 0;
}