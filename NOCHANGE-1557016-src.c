#include <stdio.h>
#define MAXN 5
#define MAXVAL 100000

char DP[MAXVAL+1];
int v[MAXN];

int main()
{
	int test=1, n, val, i, j;
	//scanf("%d", &test);
	while(test--)
	{
		scanf("%d%d", &val, &n);
		for(i=0; i<n; i++)
			scanf("%d", &v[n-i-1]);
		for(i=n-2; i>=0; i--)
			v[i]+=v[i+1];
		for(i=0; i<=val; i++)
			DP[i]=0;
		DP[v[n-1]]=DP[0]=1;
		for(i=v[n-1]+1; i<=val; i++)
			for(j=n-1; j>=0 && v[j]<=i && !DP[i]; j--)
				DP[i]=DP[i-v[j]];
		if(DP[val])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
