#include <stdio.h>
#include <math.h>

int main()
{
        int t, n;
        double p;
        scanf("%d", &t);
        while(t--)
        {
                scanf("%d%lf", &n, &p);
                printf("%lf\n", (1-pow(1-2*p, n))/2);
        }
        return 0;
}
