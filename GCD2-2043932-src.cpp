#include <iostream>
#include <sstream>

using namespace std;

int gcd(int a, int b)
{
	if(b==0)
		return a;
	return gcd(b, a%b);
}

int main()
{
	int a, b, t;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>a>>s;
		b=0;
		if(a==0)
		{
			cout<<s<<endl;
			continue;
		}
		for(int i=0; i<s.size(); i++)
		{
			b=b*10+(s[i]-'0');
			b%=a;
		}
		cout<<gcd(a, b)<<endl;
	}
	return 0;
}
