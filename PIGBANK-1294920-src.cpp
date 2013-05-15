#include <iostream>

using namespace std;

int W[500], V[500], DP[5000001];

int main(){
 int t, e, f, n;
 cin>>t;
 while(t--){
  cin>>e>>f>>n;
  for(int i=0; i<n; i++)
   cin>>V[i]>>W[i];
  DP[0]=0;
  for(int j=1; j<=f-e; j++){
   DP[j]=99999999;
   for(int i=0; i<n; i++)
    if(j-W[i]>=0 && DP[j]>DP[j-W[i]]+V[i])
     DP[j]=DP[j-W[i]]+V[i];
  }
  if(DP[f-e]==99999999)
   cout<<"This is impossible."<<endl;
  else
   cout<<"The minimum amount of money in the piggy-bank is "<<DP[f-e]<<"."<<endl;
 }
}
