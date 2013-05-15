#include <iostream>
#include <algorithm>

using namespace std;

double v[1000], h[1000];

bool mysort(double a, double b){return a>b;}

int main(){
 int t, m, n, hr, vt, i, j;
 long double c;
 cin>>t;
 while(t--){
  cin>>m>>n;
  for(i=0; i<m-1; i++)
   cin>>h[i];
  for(i=0; i<n-1; i++)
   cin>>v[i];
  c=0;
  vt=hr=1;
  sort(h, h+m-1, mysort);
  sort(v, v+n-1, mysort);
  for(i=0, j=0; i<m-1 && j<n-1; ){
   if(h[i]>v[j]){
    c+=h[i++]*vt;
    hr++;
   }
   else if(h[i]==v[j] && h[i]*vt<v[j]*hr){
    c+=h[i++]*vt;
    hr++;
   }
   else if(h[i]==v[j]){
    c+=v[j++]*hr;
    vt++;
   }
   else{
    c+=v[j++]*hr;
    vt++;
   }
  }
  for(; i<m-1; i++)
   c+=h[i]*vt;
  for(; j<n-1; j++)
   c+=v[j]*hr;
  printf("%.0Lf\n", c);
 }
 return 0;
}
