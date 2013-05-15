#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *table[101];
char s[1001];
int cnt;

int hash()
{
	int ret=0, i;
	for(i=4; s[i]; i++)
		ret=(ret+s[i]*(i-3))%101;
	ret=(19*ret)%101;
	return ret;
}

void insert(int f)
{
	int idx=hash(), j, i, free=-1;
	for(j=0; j<20; j++)
	{
		i=(idx+j*(23+j))%101;
		if(!strcmp(table[i], s+4))
		{
			if(f)
			{
				//printf("	%s deleted\n", s+4);
				table[i]="";
				cnt--;
			}
			//if(!f)
				//printf("	%s duplicate found\n", s+4);
			return;
		}
		if(free==-1 && !strlen(table[i]))
			free=i;
	}
	if(f)
		return;
	if(free==-1)
	{
		//printf("	No free location for %s\n", s+4);
		return;
	}
	table[free]=(char *)malloc(strlen(s+4)+1);
	strcpy(table[free], s+4);
	cnt++;
	//printf("	%s inserted at %d\n", s+4, free);
}

int main()
{
	int t, i, n;
	scanf("%d", &t);
	while(t--)
	{
		//Preprocessing
		cnt=0;
		for(i=0; i<101; i++)
			table[i]="";

		//Input
		scanf("%d\n", &n);
		for(i=0; i<n; i++)
		{
			gets(s);
			if(s[0]=='A')
				insert(0);
			else
				insert(1);
		}
		printf("%d\n", cnt);
		for(i=0; i<101; i++)
			if(strlen(table[i]))
				printf("%d:%s\n", i, table[i]);
	}
	return 0;
}
