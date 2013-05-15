#include <iostream>
#include <algorithm>

using namespace std;

int main(){
 int t, n;
 double rating;
 cin>>t;
 while(t>0){
  t--;
  cin>>n;
  int m[n], w[n];
  rating=0;
  for(int i=0; i<n; i++)
   cin>>m[i];
  for(int i=0; i<n; i++)
   cin>>w[i];
  sort(m, m+n);
  sort(w, w+n);
  for(int i=0; i<n; i++)
   rating+=m[i]*w[i];
  cout<<rating<<endl;
 }
 return 0;
}
