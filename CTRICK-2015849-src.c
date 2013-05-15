#include <stdio.h>

int main()
{
	int t, n, i, j, sqr, num, p, done;
	int a[20000], rmq[142];
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		
		for(sqr=1; sqr*sqr<=n; sqr++)
			;
		sqr--;
		for(i=0; i<n; i++)
			a[i]=0;
		p=(n/sqr)+(n%sqr!=0);
		for(i=0; i<p; i++)
			rmq[i]=0;

		//Add base values of i, j here
		j=-1;
		for(num=1; num<=n; num++)
		{
			int next;
			done=num;
			j=(j+1)%n;
			if(j/sqr==p-1)
				next=n;
			else
				next=(j/sqr+1)*sqr;
			for(; j<next && done; j++)
				if(!a[j])
					done--;
			j=j%n;
			i=j/sqr;
			if(!done)
				goto label;
			for(; ; i=(i+1)%p)
			{
				if(i==p-1)
					next=n-i*sqr;
				else
					next=sqr;
				if(done>=next-rmq[i])
					done-=next-rmq[i];
				else
					break;
			}
			j=i*sqr;
			for(; done; j++)
				if(!a[j])
					done--;
		label:
			for(j=j%n; a[j]; j=(j+1)%n)
				;
			a[j]=num;
			rmq[j/sqr]++;
		}

		for(i=0; i<n; i++)
			printf("%d ", a[i]);
		printf("\n");
	}
	return 0;
}
