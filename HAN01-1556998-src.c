#include <stdio.h>

char pegs[3][61], count[3];

int main()
{
	int test, n, old, i, j, tmp, target;
	long long steps, num;
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d%lld", &n, &steps);
		for(i=0; i<3; i++)
		{
			count[i]=0;
			for(j=0; j<n; j++)
				pegs[i][j]=0;
		}
		tmp=n;
		old=0;
		target=1;
		num=(1<<(n/2));
		num*=(1<<(n/2));
		if(n%2)
			num*=2;
		while(n)
		{
			if(steps>=num/2)
			{
				pegs[target][n-1]=1;
				count[target]++;
				steps-=num/2;
				old=3-old-target;
			}
			else
			{
				pegs[old][n-1]=1;
				count[old]++;
				target=3-old-target;
			}
			n--;
			num/=2;
		}
		n=tmp;
		for(i=0; i<3; i++)
		{
			printf("%d: ", i+1);
			for(j=n-1;  count[i]; j--)
				if(pegs[i][j])
				{
					printf("%d", j+1);
					count[i]--;
					if(count[i])
						printf("|");
				}
			printf("\n");
		}
	}
	return 0;
}
