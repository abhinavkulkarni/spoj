#include <stdio.h>

int main()
{
	int ret, n, i, t;
	t=1;
	while(t--)
	{
		scanf("%d", &n);
		ret=0;
		for(i=1; i<=n; i++)
		{
			if(n/i-i+1<=0)
				break;
			ret+=n/i-i+1;
		}
		printf("%d\n", ret);
	}
	return 0;
}
