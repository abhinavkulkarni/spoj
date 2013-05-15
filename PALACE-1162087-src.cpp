#include <iostream>
#include <cmath>

using namespace std;

string toBinary(int num){
 string s="";
 while(num>0){
  s+='0'+num%2;
  num/=2;
 }
 return s;
}

int Mod_Expo(long a, int b, int n){
 long double d=1;
 string s=toBinary(b);
 for(int i=s.size()-1; i>=0; i--){
  d=fmod(d*d, n);
  if(s[i]=='1')
   d=fmod(d*a, n);
 }
 return d;
}

int main(){
 int t, n;
 cin>>t;
 while(t>0){
  t--;
  cin>>n;
  cout<<Mod_Expo(2, (n-1)*(n-1), 98777)<<endl;
 }
 return 0;
}
