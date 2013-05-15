#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int R, v;
	double n;
	char s[5];
	string s1;
	while(1)
	{
		cin>>s[0];
		if(s[0]=='t')
		{
			cin>>s[0]>>R>>n;
			if(n==0)
			{
				printf("0\n");
				continue;
			}
			s1="";
			for(int i=0; n!=0; i++){
				 s1+='0'+(n-floor(n/(-R))*(-R));
				 n=ceil(n/R);
 			}
			reverse(s1.begin(), s1.end());
			cout<<s1<<endl;
		}
		else if(s[0]=='f')
		{
			cin>>s[0]>>s[1]>>s[2]>>R>>s1;
			n=0;
			v=1;
			for(int i=s1.size()-1; i>=0; i--, v*=R)
				n+=(s1[i]-'0')*v;
			cout<<n<<endl;
		}
		else
			break;
	}
	return 0;
}