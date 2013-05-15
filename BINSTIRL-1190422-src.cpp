#include <stdio.h>

main(){
 int t,  n, k, a;
 scanf("%d", &t);
 while(t--){
  scanf("%d%d", &n, &k);
  a=(n-k)&((k-1)/2);
  if(a==0)
   printf("1\n");
  else
   printf("0\n");
 }
}
