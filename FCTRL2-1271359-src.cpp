#include <iostream>
#include <sstream>

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

string mult(string s1, string s2){
 int c;
 string r="0", t;
 for(int i=0; i<s2.size(); i++){
  c=0;
  t="";
  for(int j=0; j<s1.size(); j++){
   t+='0'+(c+(s1[s1.size()-j-1]-'0')*(s2[s2.size()-i-1]-'0'))%10;
   c=(c+(s1[s1.size()-j-1]-'0')*(s2[s2.size()-i-1]-'0'))/10;
  }
  if(c!=0)
   t+='0'+c;
  t.insert(0, i, '0');
  reverse(t.begin(), t.end());
  r=add(r, t);
 }
 return r;
}

int main(){
 int t, n;
 string s;
 cin>>t;
 while(t--){
  cin>>n;
  s="1";
  for(int i=2; i<=n; i++){
   stringstream ss;
   ss<<i;
   s=mult(s, ss.str());
  }
  cout<<s<<endl;
 }
}
