#include <iostream>

using namespace std;

int main()
{
	int t, n, m, i, j, f, max;
	cin>>t;
	while(t--)
	{
		scanf("%d%d", &n, &m);
		f=0;
		max=-1;
		for(i=0; i<n; i++)
		{
			scanf("%d", &j);
			if(j>max)
				max=j;
		}
		for(i=0; i<m; i++)
		{
			scanf("%d", &j);
			if(j>max)
				f=1;
		}
		if(f==0)
			cout<<"Godzilla"<<endl;
		else
			cout<<"MechaGodzilla"<<endl;
	}
	return 0;
}
