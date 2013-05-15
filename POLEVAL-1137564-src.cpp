#include <iostream>

using namespace std;

int main(){
 int n, k, t=1;
 long double a;
 while(1){
  cin>>n;
  if(n==-1)
   break;
  int c[n+1];
  for(int i=0; i<=n; i++)
   cin>>c[i];
  cin>>k;
  int test[k];
  for(int i=0; i<k; i++)
   cin>>test[i];
  cout<<"Case "<<t++<<":"<<endl;
  for(int j=0; j<k; j++){
   a=0;
   for(int i=0; i<n; i++){
    a+=c[i];
    a*=test[j];
   }
   a+=c[n];
   printf("%.0Lf\n", a);
  }
 }
 return 0;
}
