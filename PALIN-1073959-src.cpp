#include <iostream>
#include <algorithm>

using namespace std;

string add_one(string str){
 int carry=1;
 char ch;
 for(int i=(str.size()-1)/2; i>=0; i--){
  ch=str[i];
  str[i]='0'+(str[i]-'0'+carry)%10;
  carry=(ch-'0'+carry)/10;
 }
 if(carry!=0){
  string s="";
  s+='0'+carry;
  str=s+str;
 }
 return str;
}

int main(){
 int t;
 string str, s;
 cin>>t;
 while(t>0){
  t--;
  cin>>str;
  s=str.substr(0, str.size()/2);
  reverse(s.begin(), s.end());
  if(s.compare(str.substr((str.size()+1)/2, str.size()/2))<=0)
   str=add_one(str);
  for(int i=0; i<str.size()/2; i++)
   cout<<str[i];
  if(str.size()%2==1)
   cout<<str[str.size()/2];
  for(int i=str.size()/2-1; i>=0; i--)
   cout<<str[i];
  cout<<endl;
 }
 return 0; 
}
