#include <iostream>

using namespace std;

char wt[25][25], f[25][25];
int d[25][25];

int w, h;
pair<int, int> s, dt;

void Dijkstra(){
 int min, u, v;
 d[s.first][s.second]=0;
 while(1){
  min=999999;
  for(int i=0; i<h; i++)
   for(int j=0; j<w; j++)
    if(f[i][j]=='0' && wt[i][j]!='D' && d[i][j]<min){
     min=d[i][j];
     u=i;
     v=j;
    }
  if(min==999999)
   break;
  f[u][v]='1';
  if(u-1>=0 && wt[u-1][v]!='X' && wt[u-1][v]!='S' && d[u-1][v]>d[u][v]+wt[u][v]-'0')
   d[u-1][v]=d[u][v]+wt[u][v]-'0';
  if(u+1<h && wt[u+1][v]!='X' && wt[u+1][v]!='S' && d[u+1][v]>d[u][v]+wt[u][v]-'0')
   d[u+1][v]=d[u][v]+wt[u][v]-'0';
  if(v-1>=0 && wt[u][v-1]!='X' && wt[u][v-1]!='S' && d[u][v-1]>d[u][v]+wt[u][v]-'0')
   d[u][v-1]=d[u][v]+wt[u][v]-'0';
  if(v+1<w && wt[u][v+1]!='X' && wt[u][v+1]!='S' && d[u][v+1]>d[u][v]+wt[u][v]-'0')
   d[u][v+1]=d[u][v]+wt[u][v]-'0';
 }
}

int main(){
 int min, t;
 while(1){
  scanf("%d%d", &w, &h);
  if(w==0 && h==0)
   break;
  for(int i=0; i<h; i++)
   for(int j=0; j<w; j++){
    cin>>wt[i][j];
    if(wt[i][j]=='S'){
     s=make_pair(i, j);
     wt[i][j]='0';
    }
    else if(wt[i][j]=='D')
     dt=make_pair(i, j);
    d[i][j]=999999;
    f[i][j]='0';
   }
  Dijkstra();
  printf("%d\n", d[dt.first][dt.second]);
 }
 return 0;
}
