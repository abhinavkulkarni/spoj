#include <stdio.h>

int main()
{
	int n, i;
	double f[10001];
	f[0]=f[1]=0;
	for(i=2; i<10001; i++)
		f[i]=f[i-1]+(f[i-1]+i-1)/(1.0*i);
	while(1)
	{
		scanf("%d", &n);
		if(!n)
			break;
		printf("With %d competitors, a Jedi Knight will be replaced approximately %.2lf times.\n\n", n, f[n]-f[n-1]);
	}
	return 0;
}
