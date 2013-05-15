#include <iostream>

using namespace std;

int C[100], F[100], DP[100][501];

int main(){
 int n, b, temp1, temp2;
 while(1){
  cin>>b>>n;
  if(b==0 && n==0)
   break;
  for(int i=0; i<n; i++)
   cin>>C[i]>>F[i];
  for(int i=0; i<n; i++)
   for(int j=0; j<=b; j++)
    DP[i][j]=0;
  if(C[0]<=b)
   DP[0][C[0]]=F[0];
  for(int i=1; i<n; i++)
   for(int j=1; j<=b; j++){
    DP[i][j]=DP[i-1][j];
    if(j-C[i]>=0 && DP[i][j]<DP[i-1][j-C[i]]+F[i])
     DP[i][j]=DP[i-1][j-C[i]]+F[i];
   }
  temp1=DP[n-1][b];
  temp2=b;
  for(int j=b-1; j>=0; j--)
   if(DP[n-1][j]>=temp1){
    temp1=DP[n-1][j];
    temp2=j;
   }
  cout<<temp2<<" "<<temp1<<endl;
 }
 return 0;
}
