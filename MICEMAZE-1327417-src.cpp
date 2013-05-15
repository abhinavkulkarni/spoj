#include <iostream>

using namespace std;


int main(){
 int n, e, t, m, a, b, tm;
 scanf("%d%d%d%d", &n, &e, &t, &m);
 int d[n][n][n+1];
 for(int i=0; i<n; i++)
  for(int j=0; j<n; j++)
   d[i][j][0]=99999999;
 for(int i=0; i<m; i++){
  scanf("%d%d%d", &a, &b, &tm);
  d[a-1][b-1][0]=tm;
 }
 for(int k=1; k<=n; k++)
  for(int i=0; i<n; i++)
   for(int j=0; j<n; j++)
    d[i][j][k]=min(d[i][j][k-1], d[i][k-1][k-1]+d[k-1][j][k-1]);
 tm=1;
 for(int i=0; i<n; i++)
  if(d[i][e-1][n]<=t)
   tm++;
 printf("%d\n", tm);
 return 0;
}
