#include <iostream>
#include <cmath>

using namespace std;

int main(){
 int t;
 double a, r;
 cin>>t;
 while(t>0){
  t--;
  cin>>a;
  cout<<floor(9*cbrt(16*a/(M_PI*43))/2)<<endl;
 }
 return 0;
}
