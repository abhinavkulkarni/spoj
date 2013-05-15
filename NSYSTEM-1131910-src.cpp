#include <iostream>

using namespace std;

string convert_to_string(int n){
 string s="", str="";
 s+=n/1000+'0';
 s+='m';
 n=n%1000;
 s+=n/100+'0';
 s+='c';
 n=n%100;
 s+=n/10+'0';
 s+='x';
 n=n%10;
 s+=n+'0';
 s+='i';
 for(int i=0; i<s.size(); i++)
  if(s[i]=='0')
   i++;
  else if(s[i]=='1'){
   i++;
   str+=s[i];
  }
  else
   str+=s[i];
 return str;
}

int convert(string s){
 int n=0, c=1;
 for(int i=0; i<s.size(); i++){
  if(s[i]<='9' && s[i]>='2')
   c=s[i]-'0';
  else if(s[i]=='m'){
   n+=c*1000;
   c=1;
  }
  else if(s[i]=='c'){
   n+=c*100;
   c=1;
  }
  else if(s[i]=='x'){
   n+=c*10;
   c=1;
  }
  else{
   n+=c;
   c=1;
  }
 }
 return n;
}

string sum(string s1, string s2){
 string s="";
 return s;
}

int main(){
 int t;
 string s1, s2;
 cin>>t;
 while(t>0){
  t--;
  cin>>s1>>s2;
  cout<<convert_to_string(convert(s1)+convert(s2))<<endl;
 }
 return 0;
}
