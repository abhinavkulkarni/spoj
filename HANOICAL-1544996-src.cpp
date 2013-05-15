#include <iostream>

using namespace std;

int final[2][30];

int moveall(int i, int j, int peg)
{
	if(j<0)
		return 0;
	int moves=0, old=final[i][j];
	old=peg;
	for(; j>=0; j--)
	{
		if(old==final[i][j])
			continue;
		moves+=(1<<j);
		if(old+final[i][j]==3)
			old=3;
		else if(old+final[i][j]==5)
			old=1;
		else
			old=2;
	}
	return moves;
}

int main()
{
	int n, moves, old;
	while(1)
	{
		cin>>n;
		if(!n)
			break;
		for(int i=0; i<2; i++)
			for(int j=0; j<n; j++)
				cin>>final[i][j];
		moves=0;
		for(int j=n-1; j>=0; j--)
		{
			if(final[1][j]==final[0][j])
				continue;
			old=final[0][j];
			if(old+final[1][j]==3)
				old=3;
			else if(old+final[1][j]==5)
				old=1;
			else
				old=2;
			moves+=moveall(0, j-1, old)+1+moveall(1, j-1, old);
			break;
		}
		cout<<moves<<endl;
	}
	return 0;
}
