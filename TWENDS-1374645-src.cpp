#include <iostream>

using namespace std;

int main(){
 int t=1, n, V[1000], DP[1000][1000], i, j, l;
 while(1){
  cin>>n;
  if(n==0)
   break;
  for(i=0; i<n; i++)
   cin>>V[i];
  for(i=0; i<n-1; i++)
   DP[i][i+1]=max(V[i]-V[i+1], V[i+1]-V[i]);
  for(l=4; l<=n; l++)
   for(i=0; i<n-l+1; i++){
    j=i+l-1;
    if(V[i+1]>=V[j])
     DP[i][j]=V[i]+DP[i+2][j]-V[i+1];
    else
     DP[i][j]=V[i]+DP[i+1][j-1]-V[j];
    if(V[i]>=V[j-1])
     DP[i][j]=max(DP[i][j], V[j]+DP[i+1][j-1]-V[i]);
    else
     DP[i][j]=max(DP[i][j], V[j]+DP[i][j-2]-V[j-1]);
   }
  cout<<"In game "<<t++<<", the greedy strategy might lose by as many as "<<DP[0][n-1]<<" points."<<endl;
 }
 return 0;
}
