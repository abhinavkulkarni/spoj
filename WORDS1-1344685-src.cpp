#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int din[26], dout[26], d[26];

class node{
public:
 vector<int> v;
}nodes[26];

bool BFS(int s){
 int u;
 queue<int> q;
 q.push(s);
 while(!q.empty()){
  u=q.front();
  q.pop();
  for(int i=0; i<nodes[u].v.size(); i++)
   if(d[nodes[u].v[i]]==999999){
    q.push(nodes[u].v[i]);
    d[nodes[u].v[i]]=0;
   }
 }
 for(int i=0; i<26; i++)
  if(nodes[i].v.size()!=0 && d[i]==999999)
   return false;
 return true;
}

int main(){
 int t, f, n, u=0, v[2];
 string s;
 cin>>t;
 while(t--){
  cin>>n;
  for(int i=0; i<26; i++){
   din[i]=0;
   dout[i]=0;
   d[i]=999999;
   nodes[i].v.resize(0);
  }
  for(int i=0; i<n; i++){
   cin>>s;
   din[s[s.size()-1]-'a']++;
   dout[s[0]-'a']++;
   nodes[s[0]-'a'].v.push_back(s[s.size()-1]-'a');
   nodes[s[s.size()-1]-'a'].v.push_back(s[0]-'a');
   u=s[0]-'a';
  }
  if(!BFS(u))
   cout<<"The door cannot be opened."<<endl;
  else{
  u=0;
  for(int i=0; i<26; i++)
   if(abs(din[i]-dout[i])==1){
    u++;
    if(u<=2)
     v[u-1]=i;
   }
   else if(din[i]==dout[i])
    ;
   else{
    u=3;
    break;
   }
  if(u==0)
   cout<<"Ordering is possible."<<endl;
  else if(u==2){
   f=0;
   f+=din[v[0]]-dout[v[0]]-dout[v[1]]+din[v[1]];
   if(f==0)
    cout<<"Ordering is possible."<<endl;
   else
    cout<<"The door cannot be opened."<<endl;
  }
  else
   cout<<"The door cannot be opened."<<endl;
 }
 }
 return 0;
}
