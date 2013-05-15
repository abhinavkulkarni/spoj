#include <stdio.h>

int main()
{
        int t, n, i;
        char s[81];
        scanf("%d", &t);
        for(i=1; i<=t; i++)
        {
                scanf("%d ", &n);
                gets(s);
                s[n-1]='\0';
                printf("%d %s%s\n", i, s, s+n);
        }
        return 0;
}
