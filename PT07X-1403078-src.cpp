#include <iostream>
#include <vector>

using namespace std;

int main(){
 int n, u, v, i, j, num=0;
 bool f=true;
 cin>>n;
 int d[n];
 char c[n];
 vector<vector<int> > adj(n);
 for(i=0; i<n; i++){
  d[i]=0;
  c[i]='0';
 }
 for(i=0; i<n-1; i++){
  scanf("%d%d", &u, &v);
  adj[u-1].push_back(v-1);
  adj[v-1].push_back(u-1);
  d[u-1]++;
  d[v-1]++;
 }
 while(f){
  f=false;
  for(u=0; u<n; u++){
   if(d[u]==1 && c[u]=='0'){
    f=true;
    c[u]='1';
    for(i=0; i<adj[u].size(); i++){
     if(c[adj[u][i]]=='0'){
      num++;
      c[adj[u][i]]='1';
      for(j=0; j<adj[adj[u][i]].size(); j++)
       d[adj[adj[u][i]][j]]--;
     }
    }
   }
  }
 }
 if(n<3)
  cout<<n-1<<endl;
 else
  cout<<num<<endl;
 return 0;
}
