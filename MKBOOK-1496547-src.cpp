#include <iostream>

using namespace std;

int main()
{
        int t,m, n, a[10];
        for(int test=1; ; test++)
        {
                cin>>m;
                if(m==0)
                        break;
                cin>>n;
                if(m>n)
                        swap(m, n);
                for(int i=0; i<10; i++)
                        a[i]=0;
                for(int i=m; i<=n; i++)
                {
                        int j=i;
                        while(j)
                        {
                                a[j%10]++;
                                j/=10;
                        }
                }
                cout<<"Case "<<test<<": ";
                for(int i=0; i<9; i++)
                        cout<<i<<":"<<a[i]<<" ";
                cout<<"9:"<<a[9]<<endl;
        }
        return 0;
}
