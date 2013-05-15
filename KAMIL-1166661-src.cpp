#include <iostream>
#include <cmath>
using namespace std;
int main(){int n;string s;
for(int i=0;i<10;i++){
cin>>s;
n=0;
for(int j=0;j<s.size();j++)
if(s[j]=='T'||s[j]=='D'||s[j]=='L'||s[j]=='F')
n++;
printf("%.0f\n", pow(2, (double)n));
}}
