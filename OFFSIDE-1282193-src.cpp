#include <iostream>

using namespace std;

int main(){
 int a, d, ma, f, t;
 while(1){
  cin>>a>>d;
  if(a==0 && d==0)
   break;
  ma=10001;
  f=0;
  for(int i=0; i<a; i++){
   cin>>t;
   if(t<ma)
    ma=t;
  }
  for(int i=0; i<d; i++){
   cin>>t;
   if(t<=ma)
    f++;
  }
  if(f<2)
   cout<<"Y"<<endl;
  else
   cout<<"N"<<endl;
 }
 return 0;
}
