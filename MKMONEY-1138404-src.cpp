#include <iostream>
#include <cmath>

using namespace std;

int main(){
 int t=1;
 float p, r, q, p1, I;
 while(1){
  cin>>p>>r>>q;
  if(p==0 && r==0 && q==0)
   break;
  p1=p;
  for(float i=0; i<q; i++){
   I=p1*r/(q*100);
   I=floor(I*100)/100;
   p1+=I;
  }
  printf("Case %d. $%.2f at %.2f%% APR compounded %.0f times yields $%.2f\n", t++, p, r, q, p1);
 }
}
