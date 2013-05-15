#include <stdio.h>
#include <math.h>

int main()
{
	int t, n, num, i, f;
	double r[10000], l, h, rad;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &n, &f);
		f++;
		h=-1;
		for(i=0; i<n; i++)
		{
			scanf("%lf", &r[i]);
			if(h<r[i])
				h=r[i];
		}
		l=0;
		while(h-l>0.000000001)
		{
			rad=(h+l)/2;
			num=0;
			for(i=0; i<n; i++)
				num+=floor((r[i]*r[i])/(rad*rad));
			if(num>=f)
				l=rad;
			else
				h=rad;
		}
		printf("%lf\n", M_PI*rad*rad);
	}
	return 0;
}
