#include <iostream>
#include <stack>

using namespace std;

int main(){
 int n, e, next;
 while(1){
  cin>>n;
  if(n==0)
   break;
  e=1;
  stack<int> s;
  for(int i=0; i<n; i++){
   cin>>next;
   if(e==next)
    e++;
   else if(s.empty()==true)
    s.push(next);
   else{
    while(s.empty()==false && s.top()==e){
     e++;
     s.pop();
    }
    s.push(next);
   }
  }
  while(s.empty()==false && e==s.top()){
   e++;
   s.pop();
  }
  if(s.empty()==true)
   cout<<"yes"<<endl;
  else
   cout<<"no"<<endl;
 }
}
