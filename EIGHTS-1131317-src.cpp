#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
 int t;
 cin>>t;
 long double k;
 double a;
 while(t>0){
  t--;
  cin>>k;
  a=1+floor(k/2)*3+floor((k+1)/2-1)*2;
  printf("%.0f", a);
  if(k-floor(k/2)*2==0)
   cout<<"42"<<endl;
  else
   cout<<"92"<<endl;
 }
 return 0;
}
