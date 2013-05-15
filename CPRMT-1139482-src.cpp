#include <iostream>
#include <algorithm>

using namespace std;

int main(){
 char a;
 string s1, s2;
 while(cin>>s1){
  cin>>s2;
  if(s1[0]==EOF)
   break;
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
  for(int i=0, j=0; i<s1.size() && j<s2.size();)
   if(s1[i]==s2[j]){
    cout<<s1[i];
    i++;
    j++;
   }
   else if(s1[i]<s2[j])
    i++;
   else
    j++;
  cout<<endl;
 }
 return 0;
}
