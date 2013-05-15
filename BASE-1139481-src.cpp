#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

string convert(string s, int b1, int b2){
 int n=0;
 string s1="";
 for(int i=s.size()-1; i>=0; i--){
  if(s[i]>='0' && s[i]<='9')
   n+=(s[i]-'0')*pow((double)b1, (double)(s.size()-i-1));
  else
   n+=(s[i]-'A'+10)*pow((double)b1, (double)(s.size()-i-1));
 }
 while(n>0){
  if(n%b2<10)
   s1+='0'+n%b2;
  else
   s1+='A'+n%b2-10;
  n=n/b2;
 }
 if(s1.size()>7)
  return "ERROR ";
 reverse(s1.begin(), s1.end());
 return s1;
}

int main(){
 string s;
 int b1, b2;
 while(cin>>s){
  cin>>b1>>b2;
  printf("%7s\n", convert(s, b1, b2).c_str());
 }
 return 0;
}
