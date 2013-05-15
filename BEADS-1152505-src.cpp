#include <iostream>

using namespace std;

int main(){
 int t, in, n;
 char c;
 string s, s1, s2;
 cin>>t;
 while(t>0){
  t--;
  cin>>s;
  c='z'+1;
  for(int i=0; i<s.size(); i++)
   if(s[i]<c){
    c=s[i];
    in=i;
   }
  s1=s.substr(in, s.size()-in)+s.substr(0, in);
  for(int i=0; i<s.size(); i++)
   if(s[i]==c){
    s2=s.substr(i, s.size()-i)+s.substr(0, i);
    if(s1.compare(s2)>0){
     s1=s2;
     in=i;
    }
   }
  cout<<in+1<<endl;
 }
 return 0;
}
