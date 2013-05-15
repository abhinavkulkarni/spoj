#include <iostream>
#include <cmath>

using namespace std;

int main(){
 int n;
 long double num;
 string s;
 while(1){
  scanf("%d", &n);
  if(n==0)
   break;
  scanf("\n");
  int d[n];
  for(int i=0; i<n; i++){
   d[i]=0;
   getline(cin, s);
   for(int j=0; j<s.size(); j++)
    if(s[j]=='.')
     d[i]++;
    else if(s[j]=='-')
     d[i]+=5;
  }
  num=0;
  for(int i=0; i<n; i++)
   if(i<2)
    num+=d[n-i-1]*pow(20, double(i));
   else if(i==2)
    num+=d[n-i-1]*360;
   else
    num+=d[n-i-1]*pow(20, (double)(i-2))*360;
  printf("%.0Lf\n", num);
  scanf("\n");
 }
 return 0;
}