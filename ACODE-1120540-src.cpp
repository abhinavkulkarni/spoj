#include <iostream>

using namespace std;

int num(string str){
 if(str.size()==1)
  return 1;
 string s="";
 for(int i=0; i<str.size(); i++)
  if(str[i]!='0')
   s+=str[i];
  else
   s[s.size()-1]='0';
 int n[s.size()];
 n[0]=1;
 n[1]=n[0];
 if(s[s.size()-1]!='0' && s[s.size()-2]!='0')
  if(s[s.size()-2]<'2' || (s[s.size()-2]=='2' && s[s.size()-1]<='6'))
   n[1]++;
 for(int i=2; i<s.size(); i++){
  n[i]=n[i-1];
  if(s[s.size()-i-1]!='0' && s[s.size()-i]!='0')
   if(s[s.size()-i-1]<'2' || (s[s.size()-i-1]=='2' && s[s.size()-i]<='6'))
    n[i]+=n[i-2];
 }
 return n[s.size()-1];
}

int main(){
 string str;
 while(1){
  cin>>str;
  if(str.compare("0")==0)
   break;
  cout<<num(str)<<endl;
 }
 return 0;
}
