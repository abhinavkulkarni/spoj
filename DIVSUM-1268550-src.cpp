#include <iostream>

using namespace std;

int main(){
 int t, n, s, i;
 scanf("%d", &t);
 while(t--){
  scanf("%d", &n);
  s=1;
  for(i=2; i*i<=n; i++)
   if(n%i==0){
    s+=i;
    s+=n/i;
   }
  i--;
  if(i*i==n)
   s-=i;
  printf("%d\n", s);
 }
}
