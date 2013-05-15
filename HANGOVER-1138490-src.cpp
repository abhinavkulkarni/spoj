#include <iostream>

using namespace std;

int main(){
 float h, n;
 while(1){
  cin>>h;
  if(h==0)
   break;
  n=2;
  while(h>0)
   h-=(1/n++);
  printf("%.0f card(s)\n", n-2);
 }
 return 0;
}
