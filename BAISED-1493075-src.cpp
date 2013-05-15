#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
        int t;
        long long n, a;
        string s;
        scanf("%d", &t);
        while(t--)
        {
                cin>>n;
                vector<int> v(n);
                for(long long i=0; i<n; i++)
                        cin>>s>>v[i];
                sort(v.begin(), v.end());
                a=0;
                for(long long i=0; i<n; i++)
                        a+=abs(v[i]-i-1);
                cout<<a<<endl;
        }
        return 0;
}
