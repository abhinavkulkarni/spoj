#include <iostream>

using namespace std;

int main(){
 int t, n;
 cin>>t;
 while(t>0){
  t--;
  cin>>n;
  int d[n][n];
  char ni[n][n];
  for(int i=0; i<n; i++)
   for(int j=0; j<n; j++)
    cin>>d[i][j];
  for(int i=0; i<n; i++)
   for(int j=0; j<n; j++){
    int k=0;
    for(; k<n; k++)
     if(d[i][k]+d[k][j]==d[i][j] && k!=i && k!=j){
      ni[i][j]='1';
      break;
     }
    if(k==n)
     ni[i][j]='0';
   }
  for(int i=0; i<n; i++)
   for(int j=i+1; j<n; j++)
    if(ni[i][j]=='0'){
     cout<<i+1<<" "<<j+1<<endl;
    }
 }
 return 0;
}
