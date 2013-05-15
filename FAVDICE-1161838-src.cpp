#include <iostream>
#include <cmath>

using namespace std;

int main(){
 int t;
 float a,n;
 cin>>t;
 while(t>0){
  t--;
  cin>>n;
  a=0;
  for(int i=n; i>0; i--)
   a+=n/i;
  printf("%.2f\n", a);;
 }
}
