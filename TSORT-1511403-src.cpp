#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
        int n, i;
        scanf("%d", &n);
        int a[n];
        for(i=0; i<n; i++)
                scanf("%d", &a[i]);
        sort(a, a+n);
        for(i=0; i<n; i++)
                printf("%d\n", a[i]);
        return 0;
}
