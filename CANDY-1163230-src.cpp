#include <iostream>
#include <cmath>
using namespace std;

int a[10000];

int main(){
 int n, n1;
 long double m;
 while(1){
  cin>>n;
  if(n==-1)
   break;
  m=0;
  for(int i=0; i<n; i++){
   scanf("%d", &a[i]);
   m+=a[i];
  }
  m=m/n;
  if(m!=floor(m))
   cout<<"-1"<<endl;
  else{
   n1=0;
   for(int i=0; i<n; i++)
    if(a[i]<m)
     n1+=m-a[i];
   cout<<n1<<endl;
  }
 }
 return 0;
}
