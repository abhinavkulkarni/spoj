#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int> > v;

int main(){
 int t, n, m, n1;
 scanf("%d", &t);
 while(t>0){
  t--;
  scanf("%d%d", &n, &m);
  v.resize(0);
  v.push_back(make_pair(0, 1));
  v.push_back(make_pair(1, n));
  for(int i=2; ; i++){
   n1=(v[i-2].second+n)/v[i-1].second;
   v.push_back(make_pair(n1*v[i-1].first-v[i-2].first, n1*v[i-1].second-v[i-2].second));
   if(v[i].first==1 && v[i].second==1)
    break;
  }
  for(int i=0; i<m; i++){
   scanf("%d", &n1);
   printf("%d/%d\n", v[n1-1].first, v[n1-1].second);
  }
 }
}
