#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
 int n, t=1;
 double d;
 while(1){
  scanf("%d", &n);
  if(n==0)
   break;
  if(n==1 || n==2)
   printf("Case %d, N = %d, # of different labelings = 1\n", t++, n);
  else{
   printf("Case %d, N = %d, # of different labelings = %.0f\n", t++, n, pow(n, n-2));
  }
 }
 return 0;
}
