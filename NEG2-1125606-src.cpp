#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

string toBinary(long double n){
 if(n==0)
  return "0";
 string s="";
 for(int i=0; n!=0; i++){
  s+='0'+(n-floor(n/2)*2);
  n=ceil(n/(-2));
 }
 reverse(s.begin(), s.end());
 return s;
}

int main(){
 long double n;
 cin>>n;
 cout<<toBinary(n)<<endl;
}
