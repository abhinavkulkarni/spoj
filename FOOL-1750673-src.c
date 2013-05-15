#include <stdio.h>
#include <string.h>

char isAtom[200][200], isList[200][200], isSet[200][200];
int n;
char s[201];

char ifAtom(int, int);
char ifSet(int, int);
char ifList(int, int);

char ifAtom(int i, int j)
{
	if(i<0 || j<0 || i>=n || j>=n)
		return 0;
	if(isAtom[i][j]!=-1)
		return isAtom[i][j];
	isAtom[i][j]=ifSet(i, j);
	return isAtom[i][j];
}

char ifList(int i, int j)
{
	int k;
	if(i<0 || j<0 || i>=n || j>=n)
		return 0;
	if(isList[i][j]!=-1)
		return isList[i][j];
	isList[i][j]=ifAtom(i, j);
	if(isList[i][j])
		return 1;
	for(k=i+1; k<j; k++)
		if(s[k]==',' && ifAtom(i, k-1) && ifList(k+1, j))
		{
			isList[i][j]=1;
			return 1;
		}
	isList[i][j]=0;
	return 0;
}

char ifSet(int i, int j)
{
	if(i<0 || j<0 || i>=n || j>=n)
		return 0;
	if(isSet[i][j]!=-1)
		return isSet[i][j];
	return (isSet[i][j]=ifList(i+1, j-1));
}

int main()
{
	int t, i, j, test;
	scanf("%d\n", &t);
	for(test=1; test<=t; test++)
	{
		gets(s);
		n=strlen(s);
		for(i=0; i<n; i++)
			for(j=i; j<n; j++)
				isAtom[i][j]=isList[i][j]=isSet[i][j]=-1;
		
		//Base Case for Atom
		for(i=0; i<n; i++)
			isAtom[i][i]=1;
		
		//Base Case for Set
		for(i=0; i<n; i++)
		{
			isSet[i][i]=0;
			if(s[i]!='{')
				for(j=i+1; j<n; j++)
					isSet[i][j]=0;
			if(s[i]!='}')
				for(j=i-1; j>=0; j--)
					isSet[j][i]=0;
		}
		for(i=0; i<n-1; i++)
			if(s[i]=='{' && s[i+1]=='}')
				isSet[i][i+1]=1;
			else
				isSet[i][i+1]=0;

		//Base Case for List
		for(i=0; i<n; i++)
			isList[i][i]=1;
		for(i=0; i<n-1; i++)
			isList[i][i+1]=isSet[i][i+1];
		
		i=ifSet(0, n-1);
		if(i)
			printf("Word #%d: Set\n", test);
		else
			printf("Word #%d: No Set\n", test);
	}
	return 0;
}
