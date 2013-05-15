#include <iostream>

using namespace std;

typedef pair<int, int> PI;
typedef long long LL;

int d1[100000], d2[10000];
PI x[10000], y[10000];

bool mysort(PI d1, PI d2){return d1.first<d2.first;}

int main(){
	int n, i, t, min;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		d1[0]=0;	d2[0]=0;
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &x[i].first, &y[i].first);
			x[i].second=i;	y[i].second=i;
			d1[0]+=x[i].first;	d2[0]+=y[i].first;
		}
		sort(x, x+n, mysort);
		sort(y, y+n, mysort);
		d1[x[0].second]=d1[0]-n*x[0].first;	d2[y[0].second]=d2[0]-n*y[0].first;
		for(i=1; i<n; i++)
		{
			d1[x[i].second]=d1[x[i-1].second]+(x[i].first-x[i-1].first)*(2*i-n);
			d2[y[i].second]=d2[y[i-1].second]+(y[i].first-y[i-1].first)*(2*i-n);
		}
		min=d1[0]+d2[0];
		for(i=1; i<n; i++)
			if(d1[i]+d2[i]<min)
				min=d1[i]+d2[i];
		printf("%d\n", min);
	}
	return 0;
}
