#include <stdio.h>

int main()
{
	int test, area, len;
	char ch;
	for(test = 0; test < 10; test++)
	{
		len = area = 1;
		scanf("%c", &ch);
		while(1)
		{
			//printf("	%d\n", area);
			scanf("%c", &ch);
			if(ch == 'K')
				break;
			if(ch == 'W')
			{
				area -= (len-1);
			}
			if(ch == 'E')
			{
				area += len;
			}
			if(ch == 'N')
			{
				len--;
			}
			if(ch == 'S')
			{
				len++;
				area++;
			}
		}
		printf("%d\n", area);
	}
	return 0;
}
