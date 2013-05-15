#include <iostream>

using namespace std;

int main()
{
        int t, n, cost[6100][6101], l, i;
        string s;
        cin>>t;
        for(i=0; i<6100; i++)
                cost[i][1]=0;
        while(t--)
        {
                cin>>s;
                n=s.size();
                for(i=0; i<n-1; i++)
                        if(s[i]==s[i+1])
                                cost[i][2]=0;
                        else
                                cost[i][2]=1;
                for(l=3; l<=n; l++)
                        for(i=0; i<n-l+1; i++)
                                if(s[i]==s[i+l-1])
                                        cost[i][l]=cost[i+1][l-2];
                                else
                                        cost[i][l]=min(cost[i+1][l-1], cost[i][l-1])+1;
                cout<<cost[0][n]<<endl;
        }
        return 0;
}