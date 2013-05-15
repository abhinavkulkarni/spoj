#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

vector<list<int> > adj;
vector<char> c;
int f=0;

void DFS(int u, int p){
 c[u-1]='G';
 for(list<int>::iterator itr=adj[u-1].begin(); itr!=adj[u-1].end(); itr++)
  if(c[*itr-1]=='W')
   DFS(*itr, u);
  else if(c[*itr-1]=='G' && *itr!=p){
   cout<<"NO"<<endl;
   exit(1);
  }
 c[u-1]='B';
}

int main(){
 int n, m, u, v;
 cin>>n>>m;
 if(m!=n-1)
  f=1;
 adj.resize(n);
 c.resize(n);
 for(int i=0; i<m; i++){
  cin>>u>>v;
  adj[u-1].push_back(v);
  adj[v-1].push_back(u);
 }
 if(f==0){
  fill(c.begin(), c.end(), 'W');
  DFS(1, 0);
 }
 for(int i=2; i<=n; i++)
  if(c[i-1]=='W'){
   f=1;
   break;
  }
 if(f==0)
  cout<<"YES"<<endl;
 else
  cout<<"NO"<<endl;
 return 0;
}
