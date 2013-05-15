#include <iostream>
#include <algorithm>

using namespace std;

int main(){
 int t, n, j,q;
 string str;
 cin>>t;
 while(t>0){
  t--;
  cin>>n>>str;
  int c[n][n];
  for(int i=0; i<n; i++)
   if(str[i]=='1')
    c[i][i]=1;
   else
    c[i][i]=0;
  for(int l=2; l<=n; l++)
   for(int i=0; i<n-l+1; i++){
    j=i+l-1;
    c[i][j]=-1;
    if(count(str.begin()+i, str.begin()+j+1, '1')>(j-i+1)/2)
     c[i][j]=l;
    else
     for(int k=i; k<j; k++){
      q=c[i][k]+c[k+1][j];
      if(q>c[i][j])
       c[i][j]=q;
     }
   }
  cout<<c[0][n-1]<<endl;
 }
 return 0;
}

