#include <iostream>

using namespace std;

int main(){
 int f, f1;
 string s, s1;
 while(cin>>s){
  s1="";
  f=0;
  f1=0;
  if(!(s[0]>='a' && s[0]<='z'))
   f=3;
  else
   s1+=s[0];
  if(f!=3){
   for(int i=1; i<s.size(); i++){
    if(s[i]>='a' && s[i]<='z')
     s1+=s[i];
    else if(s[i]=='_' && f==0){
     i++;
     f1=1;
     if(i==s.size()){
      f=3;
      break;
     }
     if(!(s[i]>='a' && s[i]<='z')){
      f=3;
      break;
     }
     s1+=s[i]-'a'+'A';
    }
    else if(s[i]=='_' && f==2){
     f=3;
     break;
    }
    else if(s[i]>='A' && s[i]<='Z' && (f==0||f==2) && f1==0){
     s1+='_';
     s1+=s[i]-'A'+'a';
     f=2;
    }
    else{
     f=3;
     break;
    }
   }
  }
  if(f==3)
   cout<<"Error!"<<endl;
  else
   cout<<s1<<endl;
 }
 return 0;
}
