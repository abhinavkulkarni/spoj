#include <stdio.h>

main(){
 int t, c;
 long long n;
 scanf("%d", &t);
 while(t--){
  scanf("%ld%d", &n, &c);
  if(c==0)
   printf("Airborne wins.\n");
  else
   printf("Pagfloyd wins.\n");
 }
}
