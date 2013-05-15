#include <iostream>

using namespace std;

long long l[51][51], s[51][51];

int main()
{
	int t, n, i, j, len, k;
	long long inf=((long long)1<<62);
	inf=2*(inf-1)+1;
	string a;
	cin>>t;
	while(t--)
	{
		cin>>a;
		n=(a.size()+1)/2;
		for(i=0; i<n-1; i++)
		{
			l[i][i]=s[i][i]=a[2*i]-'0';
			if(a[2*i+1]=='+')
				l[i][i+1]=s[i][i+1]=a[2*i]+a[2*i+2]-2*'0';
			else
				l[i][i+1]=s[i][i+1]=(a[2*i]-'0')*(a[2*i+2]-'0');
		}
		l[n-1][n-1]=s[n-1][n-1]=a[2*n-2]-'0';
		for(len=3; len<=n; len++)
			for(i=0; i<n-len+1; i++)
			{
				j=i+len-1;
				l[i][j]=0;
				s[i][j]=inf;
				for(k=i; k<j; k++)
					if(a[2*k+1]=='+')
					{
						l[i][j]=max(l[i][j], l[i][k]+l[k+1][j]);
						s[i][j]=min(s[i][j], s[i][k]+s[k+1][j]);
					}
					else
					{
						l[i][j]=max(l[i][j], l[i][k]*l[k+1][j]);
						s[i][j]=min(s[i][j], s[i][k]*s[k+1][j]);
					}
			}
		cout<<l[0][n-1]<<" "<<s[0][n-1]<<endl;
	}
}
