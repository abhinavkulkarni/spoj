#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
 int t;
 cin>>t;
 double z, n, a;
 while(t>0){
  t--;
  cin>>n;
  z=0;
  a=5;
  while(a<=n){
   z+=floor(n/a);
   a*=5;
  }
  printf("%.0f\n", floor(z));
 }
}
