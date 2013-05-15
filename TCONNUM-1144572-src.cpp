#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

string convert(string s, int b1, int b2){
 long double n=0;
 string s1="";
 for(int i=s.size()-1; i>=0; i--){
  if(s[i]>='0' && s[i]<='9')
   n+=(s[i]-'0')*pow((double)b1, (double)(s.size()-i-1));
  else
   n+=(s[i]-'A'+10)*pow((double)b1, (double)(s.size()-i-1));
 }
 if(n==0)
  return "0";
 while(n>0){
  if(n-b2*floor(n/b2)<10)
   s1+='0'+n-b2*floor(n/b2);
  else
   s1+='A'+n-b2*floor(n/b2)-10;
  n=floor(n/b2);
 }
 reverse(s1.begin(), s1.end());
 return s1;
}

int main(){
 int t, b1, b2;
 string s;
 cin>>t;
 while(t>0){
  t--;
  cin>>s>>b1>>b2;
  printf("%s\n", convert(s, b1, b2).c_str());
 }
 return 0;
}
