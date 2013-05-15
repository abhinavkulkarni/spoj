#include <iostream>

using namespace std;

long long fib[2][2][2], base[2][2]={{0, 1}, {1, 1}};
int m;

void power(int n, int idx)
{
	if(n==1)
	{
		for(int i=0; i<2; i++)
			for(int j=0; j<2; j++)
				fib[i][j][idx]=base[i][j];
		return;
	}
	power(n/2, 1-idx);
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++)
			fib[i][j][idx]=0;
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++)
			for(int k=0; k<2; k++)
				fib[i][j][idx]=(fib[i][j][idx]+(fib[i][k][1-idx]*fib[k][j][1-idx]))%(1<<m);
	if(n%2==1)
	{
		for(int i=0; i<2; i++)
			for(int j=0; j<2; j++)
			{
				fib[i][j][1-idx]=fib[i][j][idx];
				fib[i][j][idx]=0;
			}
		for(int i=0; i<2; i++)
			for(int j=0; j<2; j++)
				for(int k=0; k<2; k++)
					fib[i][j][idx]=(fib[i][j][idx]+fib[i][k][1-idx]*base[k][j])%(1<<m);
	}
}

int main()
{
	int t, n;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		power(n, 0);
		cout<<fib[1][1][0]<<endl;
	}
	return 0;
}
