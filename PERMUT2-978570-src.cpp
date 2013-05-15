#include <iostream>

using namespace std;

int main(){
 int n, i, *arr;
 while(1){
  cin>>n;
  if(n==0)
   break;
  arr=new int[n];
  for(i=0; i<n; i++)
   cin>>arr[i];
  for(i=0; i<n; i++)
   if(arr[arr[i]-1]!=i+1){
    cout<<"not ambiguous"<<endl;
    break;
   }
  if(i==n)
   cout<<"ambiguous"<<endl;
 }
 return 0;
}
