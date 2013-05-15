#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int t;
	double a, b, c, d;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c>>d;
		printf("%.2f\n", sqrt(4*(a*b+c*d)*(a*b+c*d)-(a*a+b*b-c*c-d*d)*(a*a+b*b-c*c-d*d))/4);
	}
	return 0;
}
