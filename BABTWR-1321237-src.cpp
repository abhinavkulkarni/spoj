#include <iostream>
#include <vector>

using namespace std;

class box{
public:
 int h, w, d;
 box(){}
 box(int hh, int ww, int dd){h=hh; w=ww; d=dd;}
};

vector<box> v;
int DP[90];

bool mysort(box b1, box b2){
 return b1.w*b1.d>b2.w*b2.d;
}

int main(){
 int n, h, w, d, maxH=0;
 while(1){
  v.resize(0);
  cin>>n;
  if(n==0)
   break;
  for(int i=0; i<n; i++){
   cin>>h>>w>>d;
   v.push_back(box(h, max(w, d), min(w, d)));
   if(!(h==w && h==d)){
    v.push_back(box(w, max(h, d), min(h, d)));
    if(w!=d)
     v.push_back(box(d, max(w, h), min(w, h)));
   }
  }
  sort(v.begin(), v.end(), mysort);
  DP[0]=v[0].h;
  maxH=v[0].h;
  for(int i=1; i<v.size(); i++){
   DP[i]=0;
   for(int j=0; j<i; j++){
    if(v[i].w<v[j].w && v[i].d<v[j].d)
     DP[i]=max(DP[i], DP[j]);
   }
   DP[i]+=v[i].h;
   maxH=max(maxH, DP[i]);
  }
  cout<<maxH<<endl;
 }
}
