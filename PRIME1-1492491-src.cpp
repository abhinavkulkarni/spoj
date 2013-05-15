#include <iostream>
#include <cmath>

using namespace std;

bool fl[100001];

int main()
{
        int n, m, t;
        cin>>t;
        while(t--)
        {
                scanf("%d%d", &n, &m);
                if(n==1)
                        n++;
                for(int i=0; i<=m-n; i++)
                        fl[i]=true;
                for(int i=2; i*i<=m; i++)
                {
                        int j;
                        for(j=(n/i)*i; j<=i || j<n; j+=i);
                        for(; j<=m; j+=i)
                                fl[j-n]=false;
                }
                for(int i=0; i<=m-n; i++)
                        if(fl[i])
                                printf("%d\n", n+i);
                if(t!=0)
                        printf("\n");
        }
        return 0;
}
