#include <iostream>

using namespace std;

int cnt[26], i, j, k;
long long fact, n, n1;

long long rank(string s)
{
	n=s.size();
	if(n==1)
		return 0;
	for(i=0; i<26; i++)
		cnt[i]=0;
	for(i=0; i<n; i++)
		cnt[s[i]-'a']++;
	n1=n;
	k=1;
	n=1;
	for(i=0; i<26; i++)
		if(cnt[i]>=2)
		{
			for(j=1; j<=cnt[i]; j++, k++)
				n=n*k/j;
		}
	for(; k<=n1; k++)
		n*=k;
	long long num=0;
	for(i=0; i<s[0]-'a'; i++)
		num+=n*cnt[i]/n1;
	return num+rank(s.substr(1, s.size()-1));
}

int main()
{
	string s;
	while(1)
	{
		getline(cin, s);
		if(s.size()==0)
			printf("%10d\n", 1);
		else if(s[0]=='#')
			break;
		else
			printf("%10lld\n", rank(s)+1);
	}
	return 0;
}
