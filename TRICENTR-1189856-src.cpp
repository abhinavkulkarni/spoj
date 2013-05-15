#include <iostream>
#include <cmath>

using namespace std;

int main(){
 int t;
 long double a, b, c, da, db, dc, A, d, R, x;
 cin>>t;
 while(t--){
  cin>>a>>da>>db>>dc;
  A=3*a*da/2;
  R=a*b*c/(4*A);
  b=2*A/(3*db);
  c=2*A/(3*dc);
  x=9*a*a*b*b*c*c/(16*A*A)-a*a-b*b-c*c;
  if(x<0)
   printf("%.3Lf 0.000\n", A);
  else{
   d=2*sqrt(9*a*a*b*b*c*c/(16*A*A)-a*a-b*b-c*c)/3;
   printf("%.3Lf %.3Lf\n", A, d);
  }
 }
 return 0;
}
