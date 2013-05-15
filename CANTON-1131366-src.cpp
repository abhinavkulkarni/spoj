#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
 int t;
 double n;
 float r1, r2, num, den;
 cin>>t;
 while(t>0){
  t--;
  cin>>n;
  r1=(-1+sqrt(8*n+1))/2;
  r2=floor(r1);
  if(r1-r2!=0)
   r2++;
  if(r2-2*floor(r2/2)==0){
   num=1;
   den=r2;
   for(double i=r2*(r2-1)/2+1; i<n; i++){
    num++;
    den--;
   }
  }
  else{
   num=r2;
   den=1;
   for(double i=r2*(r2-1)/2+1; i<n; i++){
    num--;
    den++;
   }
  }
  //cout<<"TERM "<<n<<" IS "<<num<<"/"<<den<<endl;
  printf("TERM %.0f IS %.0f/%.0f\n", n, num, den);
 }
 return 0;
}
