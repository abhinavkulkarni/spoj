#include <iostream>

using namespace std;

int main(){
 int t, n, c, m_ix, ix;
 char max;
 string s, tm;
 cin>>t;
 while(t--){
  scanf("%d%d", &n, &ix);
  s="";
  for(int i=0; i<n; i++){
   scanf("%d", &c);
   s+='0'+c;
  }
  c=1;
  while(1){
   max=s[0];
   m_ix=0;
   for(int i=1; i<s.size(); i++)
    if(s[i]>max){
     max=s[i]; 
     m_ix=i;
    }
   if(m_ix==ix){
    cout<<c<<endl;
    break;
   }
   c++;
   if(m_ix<ix)
    ix=ix-m_ix-1;
   else
    ix=s.size()-m_ix-1+ix;
   tm=s.substr(0, m_ix);
   s=s.substr(m_ix+1, s.size()-m_ix-1);
   s+=tm;
  }
 }
 return 0;
}
