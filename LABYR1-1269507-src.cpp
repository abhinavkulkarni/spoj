#include <iostream>
#include <queue>

using namespace std;

char a[1000][1000], st[1000][1000];
int r, c, d[1000][1000], m, mm;
pair<int, int> mv;
queue<pair<int, int> > q;

void BFS(int i, int j){
 int u, v;
 for(int ii=0; ii<r; ii++)
  for(int jj=0; jj<c; jj++)
   d[ii][jj]=99999;
 d[i][j]=0;
 q.push(make_pair(i, j));
 m=0;
 while(!q.empty()){
  u=q.front().first;
  v=q.front().second;
  q.pop();
  st[u][v]='1';
  if(d[u][v]>m){
   m=d[u][v];
   mv=make_pair(u, v);
  }
  if(u-1>=0 && a[u-1][v]=='.' && d[u-1][v]==99999){
   d[u-1][v]=d[u][v]+1;
   q.push(make_pair(u-1, v));
  }
  if(u+1<r && a[u+1][v]=='.' && d[u+1][v]==99999){
   d[u+1][v]=d[u][v]+1;
   q.push(make_pair(u+1, v));
  }
  if(v-1>=0 && a[u][v-1]=='.' && d[u][v-1]==99999){
   d[u][v-1]=d[u][v]+1;
   q.push(make_pair(u, v-1));
  }
  if(v+1<c && a[u][v+1]=='.' && d[u][v+1]==99999){
   d[u][v+1]=d[u][v]+1;
   q.push(make_pair(u, v+1));
  }
 }
}

int main(){
 int t;
 cin>>t;
 while(t--){
  mm=0;
  cin>>c>>r;
  for(int i=0; i<r; i++)
   for(int j=0; j<c; j++){
    cin>>a[i][j];
    st[i][j]='0';
   }
  for(int i=0; i<r; i++)
   for(int j=0; j<c; j++)
    if(a[i][j]=='.' && st[i][j]=='0'){
     BFS(i, j);
     BFS(mv.first, mv.second);
     if(m>mm)
      mm=m;
    }
  cout<<"Maximum rope length is "<<mm<<".\n";
 }
 return 0;
}
