#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class sub{
public:
 int t, count;
 string s;
 char st;
 sub *l, *r;
 sub(){l=0; r=0; st='R'; count=0;}
 sub(int tt, string ss, char stt){t=tt; s=ss; st=stt; count=1; l=0; r=0;}
};

class avg{
public:
 int total_submissions, total_teams, total_time;
 avg(){}
 avg(int a, int b, int c){total_submissions=a; total_teams=b; total_time=c;}
};

vector<sub *> v(9);
stack<sub *> s;

void insert(int t, string s, char c2, int i){
 if(v[i]==0){
  v[i]=new sub(t, s, c2);
  return;
 }
 sub *tp=v[i];
 while(1){
  if(s.compare(tp->s)==0){
   if(tp->st=='R')
    tp->count++;
   if(c2=='A' && tp->st=='R'){
    tp->t=t;
    tp->st='A';
   }
   return;
  }
  else if(s.compare(tp->s)<0 && tp->l!=0)
   tp=tp->l;
  else if(s.compare(tp->s)<0){
   tp->l=new sub(t, s, c2);
   return;
  }
  else if(s.compare(tp->s)>0 && tp->r!=0)
   tp=tp->r;
  else{
   tp->r=new sub(t, s, c2);
   return;
  }
 }
}

avg compute(int i){
 int total_time=0, total_submissions=0, total_teams=0;
 sub *tp=v[i];
 while(1){
  while(tp!=0){
   if(tp->st=='A'){
    total_time+=tp->t;
    total_submissions+=tp->count;
    total_teams++;
   }
   s.push(tp);
   tp=tp->l;
  }
  if(!s.empty()){
   tp=s.top();
   tp=tp->r;
   s.pop();
  }
  else
   break;
 }
 return avg(total_submissions, total_teams, total_time);
}

int main(){
 int test, n, t;
 string s;
 char c1, c2;
 avg tp;
 scanf("%d", &test);
 while(test--){
  scanf("%d", &n);
  for(int i=0; i<9; i++)
   v[i]=0;
  for(int i=0; i<n; i++){
   cin>>t>>s>>c1>>c2;
   insert(t, s, c2, c1-'A');
  }
  for(int i=0; i<9; i++){
   tp=compute(i);
   if(tp.total_teams==0)
    printf("%c 0\n", 'A'+i);
   else
    printf("%c %d %.2f %.2f\n", 'A'+i, tp.total_teams, (float)tp.total_submissions/tp.total_teams, (float)tp.total_time/tp.total_teams);
  }
 }
}
