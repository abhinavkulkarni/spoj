#include <iostream>

using namespace std;

int V[2000], sum[2000][2000], DP[2000][2000];

int main(){
 int n;
 cin>>n;
 for(int i=0; i<n; i++)
  cin>>V[i];
 for(int i=0; i<n; i++){
  sum[i][i]=V[i];
  DP[i][i]=V[i];
 }
 for(int i=0; i<n; i++)
  for(int j=i+1; j<n; j++)
   sum[i][j]=sum[i][j-1]+V[j];
 for(int l=2; l<=n; l++)
  for(int i=0; i<n; i++){
   int j=i+l-1;
   DP[i][j]=DP[i+1][j]+sum[i+1][j]+V[i];
   if(DP[i][j]<DP[i][j-1]+sum[i][j-1]+V[j])
    DP[i][j]=DP[i][j-1]+sum[i][j-1]+V[j];
  }
 cout<<DP[0][n-1]<<endl;
 return 0;
}
