#include <iostream>
#include <vector>
#include <list>

using namespace std;

int n, m, m_v;
vector<list<int> > adj;
vector<int> q, d;

void BFS(int u){
 int v;
 fill(d.begin(), d.end(), 99999);
 d[u-1]=0;
 q.resize(0);
 q.push_back(u);
 for(int i=0; i<n; i++){
  v=q[i];
  for(list<int>::iterator itr=adj[v-1].begin(); itr!=adj[v-1].end(); itr++)
   if(d[*itr-1]>d[v-1]+1){
    d[*itr-1]=d[v-1]+1;
    if(d[*itr-1]>m){
     m=d[*itr-1];
     m_v=*itr;
    }
    q.push_back(*itr);
   }
 }
}

int main(){
 int u, v;
 cin>>n;
 adj.resize(n);
 d.resize(n);
 for(int i=0; i<n-1; i++){
  cin>>u>>v;
  adj[u-1].push_back(v);
  adj[v-1].push_back(u);
 }
 BFS(1);
 BFS(m_v);
 cout<<m<<endl;
 return 0;
}
