#include <stdio.h>
#include <string.h>

int main()
{
	int t, i, state;
	char s[30001];
	scanf("%d\n", &t);
	while(t--)
	{
		gets(s);
		state=0;
		for(i=0; s[i]; i++)
		{
			if(state==0)
			{
				if(s[i]=='0')
					break;
				state=1;
			}
			else if(state==1)
			{
				if(s[i]=='0')
				{
					s[i]='1';
					state=0;
				}
				else
				{
					for(; s[i]; i++)
						s[i]='0'+(1-(s[i]-'0'));
					break;
				}
			}
		}
		puts(s);
	}
	return 0;
}
