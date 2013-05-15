#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int a, t, p, f;
	long long b;
	vector<int> v;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		if(b==0)
		{
			cout<<"1"<<endl;
			continue;
		}
		v.resize(0);
		v.push_back(a%10);
		p=a;
		while(1)
		{
			p=(p*a)%10;
			f=0;
			for(int i=0; i<v.size() && !f; i++)
				if(v[i]==p)
					f=1;
			if(f)
				break;
			v.push_back(p);
		}
		b=b%v.size();
		if(b!=0)
		{
			p=1;
			for(int i=0; i<b; i++)
				p=(p*a)%10;
		}
		else
		{
			p=1;
			for(int i=0; i<v.size(); i++)
				p=(p*a)%10;
		}
		cout<<p%10<<endl;
	}
	return 0;
}
