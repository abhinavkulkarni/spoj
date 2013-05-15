#include <iostream>

using namespace std;

int main(){
 int n, m[20][20], r, t;
 cin>>t;
 while(t--){
  cin>>n;
  for(int i=0; i<n; i++)
   for(int j=0; j<n; j++)
    cin>>m[i][j];
  double *p=new double[1<<n];
  for(int i=0; i<(1<<n); i++)
   p[i]=0;
  p[0]=1;
  for(int i=1; i<(1<<n); i++){
   int r=n;
   for(int j=0; j<n; j++)
    r-=(i>>j)&1;
   for(int j=0; j<n; j++){
    if((i&(1<<j))!=0){
     int ind=i^(1<<j);
     p[i]+=m[r][j]*p[ind];
    }
   }
  }
  printf("%.0f\n", p[(1<<n)-1]);
 }
 return 0;
}
