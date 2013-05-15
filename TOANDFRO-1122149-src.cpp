#include <iostream>
#include <vector>

using namespace std;

int main(){
 int n, r;
 string s;
 while(1){
  cin>>n;
  if(n==0)
   break;
  cin>>s;
  r=s.size()/n;
  char msg[r][n];
  for(int i=0; i<r; i++)
   for(int j=0; j<n; j++)
    if(i%2==0)
     msg[i][j]=s[i*n+j];
    else
     msg[i][n-j-1]=s[i*n+j];
  for(int i=0; i<n; i++)
   for(int j=0; j<r; j++)
    cout<<msg[j][i];
  cout<<endl;
 }
 return 0;
}
