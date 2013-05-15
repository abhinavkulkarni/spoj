#include <iostream>
#include <cmath>

using namespace std;



int main()
{
	int t, f;
	long long a, b, n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		f=0;
		a=0;
		b=sqrt(n)+1;
		while(a<=b)
			if(a*a+b*b==n)
				break;
			else if(a*a+b*b<n)
				a++;
			else
				b--;
		if(a>b)
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
			
	}
	return 0;
}
