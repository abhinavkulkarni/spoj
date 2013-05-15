#include <iostream>

using namespace std;

int main(){
 int t, x, y;
 cin>>t;
 while(t>0){
  t--;
  cin>>x>>y;
  if(x==y)
   cout<<2*x-x%2<<endl;
  else if(x-y==2)
   cout<<x+y-x%2<<endl;
  else
   cout<<"No Number"<<endl;
 }
}
