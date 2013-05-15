#include <iostream>

using namespace std;

int main(){
 int n, c, i;
 string s1, s2, s;
 cin>>n;
 while(n>0){
  n--;
  cin>>s1>>s2;
  s="";
  c=0;
  for(i=0; i<s1.size()&&i<s2.size(); i++){
   s+='0'+(s1[i]+s2[i]-2*'0'+c)%10;
   c=(s1[i]+s2[i]-2*'0'+c)/10;
  }
  if(i<s1.size())
   for(; i<s1.size(); i++){
    s+='0'+(s1[i]-'0'+c)%10;
    c=(s1[i]-'0'+c)/10;
   }
  else if(i<s2.size())
   for(; i<s2.size(); i++){
    s+='0'+(s2[i]-'0'+c)%10;
    c=(s2[i]-'0'+c)/10;
   }
  if(c!=0)
   s+=('0'+c);
  for(i=0; i<s.size(); i++)
   if(s[i]=='0')
    ;
  i=0;
  while(s[i]=='0')
   i++;
  for(; i<s.size(); i++)
   cout<<s[i];
  cout<<endl;
 }
 return 0;
}
