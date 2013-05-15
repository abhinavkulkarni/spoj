#include <iostream>
#include <cmath>

using namespace std;

float f(float n){
 if(n==1)
  return 1;
 if(floor(n/2)*2==n)
  return 2*f(floor(n/2))-1;
 else
  return 2*f(floor((n-1)/2))+1;
}

int main(){
 float n;
 while(1){
  cin.setf(ios::scientific);
  cin>>n;
  if(n==0)
   break;
  printf("%.0f\n", f(n));
 }
}
