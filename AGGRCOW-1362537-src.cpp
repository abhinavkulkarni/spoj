#include <iostream>

using namespace std;

int main(){
 int t, n, d, loc[100000], prev, num;
 long long low, high, x;
 cin>>t;
 while(t--){
  cin>>n>>d;
  for(int i=0; i<n; i++)
   cin>>loc[i];
  sort(loc, loc+n);
  low=0;
  high=1000000001;
  while(low<high){
   x=low+(high-low)/2;
   num=1;
   prev=loc[0];
   for(int i=0; i<n; i++)
    if(loc[i]-prev>x){
     num++;
     prev=loc[i];
    }
   if(num<d)
    high=x;
   else
    low=x+1;
  }
  cout<<low<<endl;
 }
 return 0;
}
