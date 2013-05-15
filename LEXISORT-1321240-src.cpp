#include <iostream>
#include <vector>

using namespace std;

vector<string> v;

int main(){
 int t, n;
 string s;
 scanf("%d", &t);
 while(t--){
  v.resize(0);
  scanf("%d", &n);
  while(n--){
   cin>>s;
   v.push_back(s);
  }
  sort(v.begin(), v.end());
  for(int i=0; i<v.size(); i++)
   cout<<v[i]<<endl;
 }
 return 0;
}
