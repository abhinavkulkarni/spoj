#include <stdio.h>

int main()
{
	int N[1001], i, even_sum, odd_sum, t, n;
	N[0]=N[1]=1;
	N[2]=5;
	even_sum=N[0]+N[2];
	odd_sum=N[1];
	for(i=3; i<=1000; i+=2)
	{
		N[i]=N[i-1]+N[i-2];
		N[i]+=odd_sum;
		N[i]+=2*(odd_sum+even_sum-N[i-1]);

		odd_sum+=N[i];
		N[i+1]=N[i]+N[i-1];
		N[i+1]+=even_sum;
		N[i+1]+=2*(odd_sum+even_sum-N[i]);
		even_sum+=N[i+1];
	}

	scanf("%d", &t);
	for(i=1; i<=t; i++)
	{
		scanf("%d", &n);
		printf("%d %d\n", i, N[n]);
	}
	return 0;
}
