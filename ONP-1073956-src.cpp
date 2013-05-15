#include <iostream>
#include <stack>

using namespace std;

int f(char ch){
 if(ch=='+' || ch=='-')
  return 1;
 if(ch=='*' || ch=='/')
  return 3;
 if(ch=='^')
  return 6;
 if(ch=='(')
  return 9;
 if(ch==')')
  return 0;
 else
  return 7;
}

int g(char ch){
 if(ch=='+' || ch=='-')
  return 2;
 if(ch=='*' || ch=='/')
  return 4;
 if(ch=='^')
  return 5;
 if(ch=='(')
  return 0;
 else
  return 8;
}

int main(){
 int t, i;
 string str, pol;
 char ch;
 stack<char> s;
 cin>>t;
 while(t>0){
  t--;
  cin>>str;
  str+=')';
  pol="";
  s.push('(');
  i=0;
  while(i<str.size()){
   ch=str[i++];
   while(f(ch)<g(s.top())){
    pol+=s.top();
    s.pop();
   }
   if(f(ch)!=g(s.top()))
    s.push(ch);
   else
    s.pop();
  }
  cout<<pol<<endl;
 }
 return 0;
}
