#include <iostream>
#include <string.h>

using namespace std;

int main()
{
        int n, t, l, i, j, max;
        string s;
        scanf("%d", &t);
        getchar();
        for(i=1; i<=t; i++)
        {
                getline(cin, s);
                n=s.size();
                l=max=0;
                for(j=0; j<n; j++)
                        if(s[j]=='[')
                        {
                                l++;
                                if(l>max)
                                        max=l;
                        }
                        else
                                l--;
                printf("%d %d\n", i, (1<<max));
        }
        return 0;
}
