#include <iostream>

using namespace std;

int Time[50][50], Toll[50][50], Min[50][1001], n, t;
char f[50][1001];
pair<int, int> a;

void Dijkstra(){
 int min, k, l;
 for(int i=0; i<n; i++)
  for(int j=0; j<=t; j++){
   Min[i][j]=999999;
   f[i][j]='0';
  }
 Min[0][t]=0;
 while(1){
  min=999999;
  for(int i=0; i<n; i++)
   for(int j=0; j<=t; j++)
    if(Min[i][j]<min && f[i][j]=='0'){
     min=Min[i][j];
     k=i;
     l=j;
    }
  if(min==999999)
   break;
  f[k][l]='1';
  for(int i=0; i<n; i++)
   if(i!=k && l-Time[k][i]>=0 && Min[i][l-Time[k][i]]>Min[k][l]+Toll[k][i])
    Min[i][l-Time[k][i]]=Min[k][l]+Toll[k][i];
 }
 a=make_pair(Min[n-1][0], 0);
 for(int j=1; j<=t; j++)
  if(Min[n-1][j]<=a.first)
   a=make_pair(Min[n-1][j], j);
}

int main(){
 while(1){
  cin>>n>>t;
  if(n==0 && t==0)
   break;
  for(int i=0; i<n; i++)
   for(int j=0; j<n; j++)
    cin>>Time[i][j];
  for(int i=0; i<n; i++)
   for(int j=0; j<n; j++)
    cin>>Toll[i][j];
  Dijkstra();
  cout<<a.first<<" "<<t-a.second<<endl;
 }
 return 0;
}
