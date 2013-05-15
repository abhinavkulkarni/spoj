#include <iostream>
#include <cmath>

using namespace std;

double coins[1000];

double N(double n){
 if(n<1000)
  return coins[(int)n];
 return max(n, N(floor(n/2))+N(floor(n/3))+N(floor(n/4)));
}

int main(){
 double t, n;
 for(int i=0; i<12; i++)
  coins[i]=i;
 for(int i=12; i<1000; i++){
  t=coins[i/2]+coins[i/3]+coins[i/4];
  if(i>t)
   coins[i]=i;
  else
   coins[i]=t;
 }
 while(cin>>n)
  printf("%.0f\n", N(n));
 return 0;
}