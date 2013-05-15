#include <stdio.h>

int a, m;

int mod(long long n)
{
	if(n==1)
		return a%m;
	int ret=mod(n/2);
	long long mod=ret;
	mod=(mod*ret)%m;
	if(n%2)
		mod=(mod*a)%m;
	return mod;
}

int main()
{
	int t;
	long long n;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%lld%d", &a, &n, &m);
		printf("%d\n", mod(n));
	}
	return 0;
}
