#include <iostream>
#include <cstring>

#define ok(a, b, c) (a<b+c && b<c+a && c<b+a)

using namespace std;

int DP[3][3][3][3][3][3][3][3][3][3][3][3][3], a[13];

int doit()
{
	if(DP[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]][a[6]][a[7]][a[8]][a[9]][a[10]][a[11]][a[12]]!=-1)
		return DP[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]][a[6]][a[7]][a[8]][a[9]][a[10]][a[11]][a[12]];
	int &res=DP[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]][a[6]][a[7]][a[8]][a[9]][a[10]][a[11]][a[12]];
	res=0;
	for(int i=0; i<13; i++)
	{
		if(a[i]<=0)
			continue;
		a[i]--;
		for(int j=i; j<13; j++)
		{
			if(a[j]<=0)
				continue;
			a[j]--;
			for(int k=j; k<13; k++)
			{
				a[k]--;
				if(a[i]>=0 && a[j]>=0 && a[k]>=0 && ok(i+1, j+1, k+1))
					res=max(res, 1+doit());
				a[k]++;
			}
			a[j]++;
		}
		a[i]++;
	}
	return res;
}

int main()
{
	int n, i, x;
	int num[2][13], triples[2];
	DP[0][0][0][0][0][0][0][0][0][0][0][0][0]=0;
	for(int b=0; b<3; b++)
	for(int c=0; c<3; c++)
	for(int d=0; d<3; d++)
	for(int e=0; e<3; e++)
	for(int f=0; f<3; f++)
	for(int g=0; g<3; g++)
	for(int h=0; h<3; h++)
	for(int i=0; i<3; i++)
	for(int j=0; j<3; j++)
	for(int k=0; k<3; k++)
	for(int l=0; l<3; l++)
	for(int m=0; m<3; m++)
	for(int n=0; n<3; n++)
		DP[b][c][d][e][f][g][h][i][j][k][l][m][n]=-1;
	while(1)
	{
		scanf("%d", &n);
		if(!n)
			break;
		for(x=0; x<2; x++)
			for(i=0; i<13; i++)
				num[x][i]=0;
		for(i=0; i<n; i++)
		{
			scanf("%d", &x);
			num[i%2][x-1]++;
		}
		triples[0]=triples[1]=0;
		for(x=0; x<2; x++)
			for(i=0; i<13; i++)
			{
				triples[x]+=num[x][i]/3;
				num[x][i]%=3;
			}
		if(triples[0]>triples[1])
		{
			printf("1\n");
			continue;
		}
		if(triples[0]<triples[1])
		{
			printf("2\n");
			continue;
		}
		
		for(x=0; x<2; x++)
		{
			for(i=0; i<13; i++)
				a[i]=num[x][i];
			triples[x]=doit();
		}
		if(triples[0]>triples[1])
		{
			printf("1\n");
			continue;
		}
		if(triples[0]<triples[1])
		{
			printf("2\n");
			continue;
		}
		printf("0\n");
	}
	return 0;
}
