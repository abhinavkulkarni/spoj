#include <iostream>
using namespace std;

int m[101];
pair<int, int> sm[101][101];

int main(){
 int n;
 while(scanf("%d", &n)==1){
  for(int i=0; i<n; i++)
   scanf("%d", &m[i]);
  for(int i=0; i<n; i++)
   sm[i][i]=make_pair(m[i], 0);
  for(int l=2; l<=n; l++){
   for(int i=0; i<n-l+1; i++){
    int j=i+l-1;
    sm[i][j]=make_pair(0, 999999);
    for(int k=i; k<j; k++)
     if(sm[i][k].first*sm[k+1][j].first+sm[i][k].second+sm[k+1][j].second<sm[i][j].second){
      sm[i][j].second=sm[i][k].first*sm[k+1][j].first+sm[i][k].second+sm[k+1][j].second;
      sm[i][j].first=(sm[i][k].first+sm[k+1][j].first)%100;
     }
   }
  }
  printf("%d\n", sm[0][n-1].second);
 }
 return 0;
}
