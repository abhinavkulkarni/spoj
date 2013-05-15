#include <iostream>
#include <cmath>

using namespace std;

int main(){
 int t, n, i;
 long double s, a;
 scanf("%d", &t);
 while(t--){
  cin>>n;
  s=0;
  for(i=0; i<n; i++){
   cin>>a;
   s=fmod(s+a, n);
  }
  if(s==0)
   printf("YES\n");
  else
   printf("NO\n");
 }
}
