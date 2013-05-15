#include <iostream>

using namespace std;

long double w[201][201], e[201][201];
int p[200], q[201];

int main(){
 int n;
 long double t,s;
 while(1){
  scanf("%d",&n);
  if(n==0)
   break;
  s=0;
  for(int i=0; i<n; i++)
   scanf("%d",&p[i]);
  for(int i=0; i<=n; i++){
   scanf("%d",&q[i]);
   s+=q[i];
  }
  for(int i=1; i<=n+1; i++){
   e[i-1][i-1]=q[i-1];
   w[i-1][i-1]=q[i-1];
  }
  for(int l=1; l<=n; l++){
   for(int i=1; i<=n-l+1; i++){
    int j=i+l-1;
    e[i-1][j]=999999999;
    w[i-1][j]=w[i-1][j-1]+p[j-1]+q[j];
    for(int r=i; r<=j; r++){
     t=e[i-1][r-1]+e[r][j]+w[i-1][j];
     if(t<e[i-1][j])
      e[i-1][j]=t;
    }
   }
  }
  printf("%.0Lf\n",e[0][n]-s);
 }
 return 0;
}
