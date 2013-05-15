#include <iostream>
#include <set>
#include <map>
#include <stack>

using namespace std;

int main()
{
	int t, n, val, tmp;
	char str[15];
	stack<int> st;
	set<int> s[2];
	map<set<int>, int> mp;
	map<set<int>, int>::iterator itr;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		mp.clear();
		val=-1;
		s[0].clear();
		mp[s[0]] = ++val;
		while(!st.empty())
			st.pop();
		for(int i=0; i<n; i++)
		{
			scanf("%s", str);
			if(str[0]=='P')
			{
				st.push(0);
				printf("0\n");
			}
			else if(str[0]=='D')
			{
				for(itr=mp.begin(); itr!=mp.end(); itr++)
					if(itr->second==st.top())
					{
						s[0]=itr->first;
						break;
					}
				st.push(st.top());
				printf("%d\n", s[0].size());
			}
			else if(str[0]=='A')
			{
				tmp=st.top();
				st.pop();
				for(itr=mp.begin(); itr!=mp.end(); itr++)
					if(itr->second==st.top())
					{
						s[1]=itr->first;
						st.pop();
						break;
					}
				s[1].insert(tmp);
				if(mp.count(s[1])==0)
					mp[s[1]]=++val;
				st.push(mp[s[1]]);
				printf("%d\n", s[1].size());
			}
			else if(str[0]=='U')
			{
				for(int i=0; i<2; i++)
					for(itr=mp.begin(); itr!=mp.end(); itr++)
						if(itr->second==st.top())
						{
							s[i]=itr->first;
							st.pop();
							break;
						}
				s[1].insert(s[0].begin(), s[0].end());
				if(mp.count(s[1])==0)
					mp[s[1]]=++val;
				st.push(mp[s[1]]);
				printf("%d\n", s[1].size());
			}
			else if(str[0]=='I')
			{
				set<int>::iterator itr1, itr2;
				set<int> tmp_set;
				for(int i=0; i<2; i++)
					for(itr=mp.begin(); itr!=mp.end(); itr++)
				    		if(itr->second==st.top())
				            	{
					        	s[i]=itr->first;
					    		st.pop();
							break;
						}
				for(itr1=s[0].begin(), itr2=s[1].begin(); itr1!=s[0].end() && itr2!=s[1].end(); )
					if(*itr1<*itr2)
						itr1++;
					else if(*itr1>*itr2)
						itr2++;
					else
					{
						tmp_set.insert(*itr1);
						itr1++;
						itr2++;
					}
				if(mp.count(tmp_set)==0)
					mp[tmp_set]=++val;
				st.push(mp[tmp_set]);
				printf("%d\n", tmp_set.size());
			}
		}
		printf("***\n");
	}
	return 0;
}
