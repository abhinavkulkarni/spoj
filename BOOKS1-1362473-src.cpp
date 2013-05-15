#include <iostream>

using namespace std;

int t, n, books[500], idx[500], workers, i, j;

void getMostWork(){
 int required, current_load, x, low=0, high=500*1000000;
 while(low<high){
  x=low+(high-low)/2;
  current_load=0;
  required=1;
  for(i=0; i<n; i++)
   if(current_load+books[i]<=x)
    current_load+=books[i];
   else{
    required++;
    current_load=books[i];
    if(current_load>x)
     required=workers+1;
   }
  if(required<=workers)
   high=x;
  else
   low=x+1;
 }
 current_load=0;
 for(i=n-1, j=workers-1; i>=0; i--)
  if(i>=j){
   if(current_load+books[i]<=low)
    current_load+=books[i];
   else{
    idx[--j]=i;
    current_load=books[i];
   }
  }
  else{
   while(i>=0)
    idx[--j]=i--;
  }
 if(workers>1){
  for(i=0, j=0; j<workers-1; i++)
   if(i<idx[j])
    cout<<books[i]<<" ";
   else{
    cout<<books[i]<<" / ";
    j++;
   }
  for(; i<n-1; i++)
   cout<<books[i]<<" ";
  cout<<books[n-1]<<endl;
 }
 else{
  for(i=0; i<n-1; i++)
   cout<<books[i]<<" ";
  cout<<books[n-1]<<endl;
 }
}

int main(){
 cin>>t;
 while(t--){
  cin>>n>>workers;
  for(i=0; i<n; i++)
   cin>>books[i];
  getMostWork();
 }
 return 0;
}
