#include <stdio.h>

int main()
{
	int t, c1, c2, c3, c1in, c2in, c3in, d;
	int DP[12][12][12][31], *r;

	for(c1=0; c1<=11; c1++)
		for(c2=0; c2<=11; c2++)
			for(c3=0; c3<=11; c3++)
				DP[c1][c2][c3][0]=0;
	DP[0][0][0][0]=1;
	for(d=1; d<=30; d++)
		for(c1=0; c1<=11; c1++)
			for(c2=0; c2<=11; c2++)
				for(c3=0; c3<=11; c3++)
					if(c1+c2+c3==0)
						DP[c1][c2][c3][d]=1;
					else if(c1+c2+c3<d)
						DP[c1][c2][c3][d]=DP[c1][c2][c3][d-1];
					else
					{
						r=&DP[c1][c2][c3][d];
						*r=0;
						for(c3in=0; c3in<c3; c3in++)
							*r=(*r+DP[0][0][c3in][d-1]*DP[c1][c2][c3-c3in-1][d])%11380;
						for(c3in=0; c3in<=c3; c3in++)
							for(c2in=0; c2in<c2; c2in++)
								*r=(*r+DP[0][c2in][c3in][d-1]*DP[c1][c2-c2in-1][c3-c3in][d])%11380;
						for(c3in=0; c3in<=c3; c3in++)
							for(c2in=0; c2in<=c2; c2in++)
								for(c1in=0; c1in<c1; c1in++)
									*r=(*r+DP[c1in][c2in][c3in][d-1]*DP[c1-c1in-1][c2-c2in][c3-c3in][d])%11380;
					}
	for(t=0; t<10; t++)
	{
		scanf("%d%d%d%d", &c1, &c2, &c3, &d);
		if(d==0)
			printf("%d\n", DP[c1][c2][c3][d]);
		else
			printf("%d\n", (11380+DP[c1][c2][c3][d]-DP[c1][c2][c3][d-1])%11380);

	}
	return 0;
}
