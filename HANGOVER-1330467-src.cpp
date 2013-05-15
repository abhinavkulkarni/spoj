#include <iostream>

using namespace std;

int main(){
 float n, h, c;
 while(1){
  scanf("%f", &c);
  if(c==0)
   break;
  h=0;
  n=2;
  while(h<c)
   h+=1/n++;
  printf("%.0f card(s)\n", n-2);
 }
 return 0;
}
