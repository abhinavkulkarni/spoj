#include <iostream>

using namespace std;

int main(){
 int t, n, k;
 cin>>t;
 while(t>0){
  t--;
  cin>>n>>k;
  n=n-k;
  if(n==0){
   printf("1\n");
   continue;
  }
  double a[n+1][k];
  for(int j=0; j<k; j++)
   a[0][j]=1;
  for(int i=0; i<=n; i++)
   a[i][0]=1;
  for(int i=1; i<=n; i++)
   for(int j=1; j<k; j++)
    a[i][j]=a[i-1][j]+a[i][j-1];
  printf("%.0f\n", a[n][k-1]);
 }
 return 0;
}
