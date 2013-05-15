#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

int main(){
 int t, u, v, n, m;
 cin>>t;
 while(t>0){
  t--;
  cin>>n>>m;
  char b[n][m];
  int d[n][m];
  queue<pair<int, int> > q;
  for(int i=0; i<n; i++)
   for(int j=0; j<m; j++){
    d[i][j]=99999;
    cin>>b[i][j];
    if(b[i][j]=='1'){
     q.push(make_pair(i+1, j+1));
     d[i][j]=0;
    }
   }
  while(q.empty()==false){
   u=q.front().first-1;
   v=q.front().second-1;
   q.pop();
   for(int i=u-1; i<=u+1; i++)
    for(int j=v-1; j<=v+1; j++)
     if(!(i==u && j==v)){
      if(i>=0 && i<n && j>=0 && j<m)
       if(d[i][j]>d[u][v]+abs(i-u)+abs(j-v)){
        d[i][j]=d[u][v]+abs(i-u)+abs(j-v);
	q.push(make_pair(i+1, j+1));
       }
     }
  }
  for(int i=0; i<n; i++){
   int j=0;
   for(; j<m-1; j++)
    cout<<d[i][j]<<" ";
   cout<<d[i][j]<<endl;
  }
 }
 return 0;
}
