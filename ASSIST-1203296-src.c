#include <stdio.h>

int main(){
 int t, c=0, a[33850], p=0, i=0, j;
 char f[33850];
 for(; i<33850; i++){
  a[i]=i;
  f[i]='0';
 }
 for(i=2; i<33850; i++){
  if(f[i]=='0'){
   a[p++]=a[i];
   t=a[i];
   for(j=i+1; j<33850; j++)
    if(f[j]=='0'){
     t--;
     if(t==0){
      t=a[i];
      f[j]='1';
     }
    }
  }
 }
 while(1){
  scanf("%d", &c);
  if(c==0)
   break;
  else
   printf("%d\n", a[c-1]);
 }
 return 0;
}
