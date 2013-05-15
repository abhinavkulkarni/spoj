#include <iostream>

using namespace std;

string add(string s1, string s2){
 int c=0, i;
 string s="";
 if(s1.size()<s2.size())
  swap(s1, s2);
 for(i=0; i<s2.size(); i++){
  s+='0'+(s1[s1.size()-i-1]+s2[s2.size()-i-1]-2*'0'+c)%10;
  c=(s1[s1.size()-i-1]+s2[s2.size()-i-1]+c-2*'0')/10;
 }
 for(; i<s1.size(); i++){
  s+='0'+(s1[s1.size()-i-1]+c-'0')%10;
  c=(s1[s1.size()-i-1]+c-'0')/10;
 }
 if(c!=0)
  s+='0'+c;
 reverse(s.begin(), s.end());
 return s;
}

string sub(string s1, string s2){
 int c=0, i=0;
 string s="";
 for(; i<s2.size(); i++){
  if(s1[s1.size()-i-1]-s2[s2.size()-i-1]-c>=0){
   s+='0'+(s1[s1.size()-i-1]-s2[s2.size()-i-1]-c);
   c=0;
  }
  else{
   s+='0'+(s1[s1.size()-i-1]-s2[s2.size()-i-1]-c+10);
   c=1;
  }
 }
 for(; i<s1.size(); i++){
  if(s1[s1.size()-i-1]-c>='0'){
   s+=s1[s1.size()-i-1]-c;
   c=0;
  }
  else{
   s+=s1[s1.size()-i-1]-c+10;
   c=1;
  }
 }
 reverse(s.begin(), s.end());
 for(i=0; i<s.size() && s[i]=='0'; i++)
  ;
 s=s.substr(i, s.size()-i);
 if(s.size()==0)
  s="0";
 return s;
}

string devide_by_two(string s){
 int i=0;
 string d="";
 int n=0;
 for(; i<s.size(); i++){
  d+='0'+(n+s[i]-'0')/2;
  n=10*((s[i]-'0')%2);
 }
 for(i=0; i<d.size() && d[i]=='0'; i++)
  ;
 d=d.substr(i, d.size()-i);
 if(d.size()==0)
  d="0";
 return d;
}

int main(){
 string s1, s2;
 for(int i=0; i<10; i++){
  cin>>s1>>s2;
  cout<<devide_by_two(add(s1, s2))<<endl<<devide_by_two(sub(s1, s2))<<endl;
 }
 return 0;
}
