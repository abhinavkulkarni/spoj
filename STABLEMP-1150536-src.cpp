#include <iostream>

using namespace std;

int main(){
 int t, n, c, num;
 cin>>t;
 while(t>0){
  t--;
  cin>>n;
  int pm[n][n+1], pw[n][n+1];
  for(int i=0; i<n; i++){
   pm[i][n]=-1;
   pw[i][n]=-1;
   cin>>c;
   for(int j=0; j<n; j++){
    cin>>num;
    pw[c-1][num-1]=n-j;
   }
  }
  for(int i=0; i<n; i++){
   cin>>c;
   for(int j=0; j<n; j++){
    cin>>num;
    pm[c-1][num-1]=n-j;
   }
  }
  c=0;
  for(int i=0; c<n; i=(i+1)%n){
   if(pm[i][n]==-1){
    int m=-1, w;
    for(int j=0; j<n; j++)
     if(pm[i][j]>0 && pm[i][j]>m){
      m=pm[i][j];
      w=j;
     }
    if(pw[w][n]==-1){
     pw[w][n]=i;
     pm[i][n]=w;
     c++;
     //cout<<"Marriage between "<<i+1<<" & "<<w+1<<" fixed"<<endl;
    }
    else if(pw[w][i]>pw[w][pw[w][n]]){
     //cout<<"Marraige between "<<pw[w][n]+1<<" & "<<w+1<<" broken"<<endl;
     pm[pw[w][n]][n]=-1;
     pm[pw[w][n]][w]*=-1;
     pw[w][n]=i;
     pm[i][n]=w;
     //cout<<"Marriage between "<<i+1<<" & "<<w+1<<" fixed"<<endl;
    }
    else
     pm[i][w]*=-1;
   }
  }
  for(int i=0; i<n; i++)
   cout<<i+1<<" "<<pm[i][n]+1<<endl;
 }
 return 0;
}
