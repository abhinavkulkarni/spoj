#include <iostream>

using namespace std;

bool beat[100][100], winner[100], can[100][100][100];

int main()
{
	int test, n, i, j, l, num, s, t, n1, n2, k;
	char ch;
	cin>>test;
	while(test--)
	{
		cin>>n;
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
			{
				cin>>ch;
				beat[i][j]=(ch=='1');
			}
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				for(k=0; k<n; k++)
					can[i][j][k]=false;
		for(i=0; i<n; i++)
		{
			can[i][i][i]=true;
			can[i][(i+1)%n][i]=beat[i][(i+1)%n];
			can[i][(i+1)%n][(i+1)%n]=beat[(i+1)%n][i];
		}
		for(l=3; l<=n; l++)
			for(i=0; i<n; i++)
			{
				j=(i+l-1)%n;
				for(num=1; num<l-1; num++)
				{
					k=(i+num)%n;
					for(n1=0; n1<num && !can[i][j][k]; n1++)
					{
						s=(i+n1)%n;
						if(can[i][(n+k-1)%n][s] && beat[k][s])
							for(n2=num+1; n2<=l-1 && !can[i][j][k]; n2++)
							{
								t=(i+n2)%n;
								if(can[(k+1)%n][j][t] && beat[k][t])
									can[i][j][k]=true;
							}
					}
				}
				for(n2=1; n2<=l-1 && !can[i][j][i]; n2++)
				{
					t=(i+n2)%n;
					if(can[(i+1)%n][j][t] && beat[i][t])
						can[i][j][i]=true;
				}
				for(n1=0; n1<l-1 && !can[i][j][j]; n1++)
				{
					s=(i+n1)%n;
					if(can[i][(n+j-1)%n][s] && beat[j][s])
						can[i][j][j]=true;
				}
			}
		num=0;
		for(i=0; i<n; i++)
		{
			winner[i]=0;
			for(k=0; k<n; k++)
				if(can[k][(k+n-1)%n][i])
				{
					num++;
					winner[i]=true;
					break;
				}
		}
		cout<<num<<endl;
		for(i=0; i<n; i++)
			if(winner[i])
				cout<<i+1<<endl;
	}
	return 0;
}
