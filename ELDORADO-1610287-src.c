#include <stdio.h>

int main()
{
	int n, k, i, j, l;
	long long DP[100][100], ans;
	int a[100];
	while(1)
	{
		scanf("%d%d", &n, &k);
		for(i=0; i<n; i++)
			scanf("%d", &a[i]);
		if(n+k==0)
			break;
		for(i=0; i<n; i++)
			for(l=0; l<k; l++)
				DP[i][l]=0;
		for(i=0; i<n; i++)
			DP[i][0]=1;
		for(l=2; l<=k; l++)
			for(i=0; i<n; i++)
				for(j=0; j<i; j++)
					if(a[i]>a[j])
						DP[i][l-1]+=DP[j][l-2];
		ans=0;
		for(i=0; i<n; i++)
			ans+=DP[i][k-1];
		printf("%lld\n", ans);
	}
	return 0;
}
