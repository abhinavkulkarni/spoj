#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
 int t;
 long double num, n;
 cin>>t;
 while(t>0){
  t--;
  cin>>n;
  num=(n*(n+1)*(2*n+3)/2-4*n+7*n/2)/4;
  printf("%.0Lf\n", num);
 }
 return 0;
}
