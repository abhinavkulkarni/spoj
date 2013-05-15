#include <iostream>
#include <vector>

using namespace std;

class order{
public:
 int s, f, v;
 order(){}
 order(int s1, int f1, int v1){s=s1; f=f1; v=v1;}
};

int n;
vector<order> a(10000);
vector<double> vl(10000);

bool comp_funct(order a, order b){
 return a.s<=b.s;
}

void DP(){
 vl[n-1]=a[n-1].v;
 for(int i=n-1; i>0; i--){
  int j=i+1;
  for(; j<=n && a[j-1].s<a[i-1].s+a[i-1].f; j++)
   ;
  if(j==n+1)
   vl[i-1]=max((double)a[i-1].v, vl[i]);
  else
   vl[i-1]=max(a[i-1].v+vl[j-1], vl[i]);
 }
 printf("%.0f\n", vl[0]);
}

int main(){
 int t, s, f, v;
 cin>>t;
 while(t>0){
  t--;
  cin>>n;
  for(int i=0; i<n; i++){
   scanf("%d %d %d", &s, &f, &v);
   a[i]=order(s, f, v);
  }
  sort(a.begin(), a.begin()+n, comp_funct);
  DP();
 }
 return 0;
}
