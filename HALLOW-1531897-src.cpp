#include <iostream>

using namespace std;

int main()
{
	int c, n, i, sum, s, j;
	pair<char, int> a[100000];
	while(1)
	{
		scanf("%d%d", &c, &n);
		if(c==0 && n==0)
			break;
		sum=0;
		for(i=1; i<c; i++)
			a[i].first=0;
		a[0].second=-1;
		a[0].first=1;
		for(i=0; i<n; i++)
		{
			scanf("%d", &s);
			sum=(sum+s)%c;
			if(a[sum].first==0)
			{
				a[sum].first=1;
				a[sum].second=i;
			}
			else
			{
				for(j=a[sum].second+1; j<i; j++)
					printf("%d ", j+1);
				printf("%d\n", j+1);
				for(i=i+1; i<n; i++)
					scanf("%d", &s);
				break;
			}
		}	
	}
	return 0;
}
