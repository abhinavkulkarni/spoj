#include <iostream>

using namespace std;

int main()
{
	int t, i, j, low, high, mid, cnt;
	string s1, s2;
	cin>>t;
	while(t--)
	{
		cin>>s1>>s2;
		low=0;
		high=s2.size()/s1.size()+1;
		while(high-low>1)
		{
			mid=(low+high)/2;
			j=0;
			for(i=0; i<s1.size(); i++)
			{
				for(cnt=0; j<s2.size() && cnt<mid; j++)
					if(s1[i]==s2[j])
						cnt++;
				if(cnt==mid)
					continue;
				else
					break;
			}
			if(i!=s1.size())
				high=mid;
			else
				low=mid;
		}
		cout<<low<<endl;
	}
	return 0;
}
