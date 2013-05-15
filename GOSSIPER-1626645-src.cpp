#include <iostream>
#include <map>

using namespace std;

int main()
{
	int n, m, i, j, idx1, idx2;
	bool f[2100][2100];
	string s1, s2;
	map<string, int> mp;
	while(1)
	{
		scanf("%d%d", &n, &m);
		if(n==0 && m==0)
			break;
		mp.clear();
		for(i=0; i<n; i++)
		{
			cin>>s1;
			mp.insert(make_pair(s1, i));
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
				f[i][j]=false;
			f[i][i]=true;
		}
		for(i=0; i<m; i++)
		{
			cin>>s1>>s2;
			idx1=mp[s1];
			idx2=mp[s2];
			for(j=0; j<n; j++)
				if(f[idx1][j] || f[idx2][j])
				{
					f[idx1][j]=true;
					f[idx2][j]=true;
				}
		}
		idx1=0;
		for(i=0; i<n && !idx1; i++)
			for(j=0; j<n; j++)
				if(!f[i][j])
				{
					idx1=1;
					break;
				}
		if(!idx1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
