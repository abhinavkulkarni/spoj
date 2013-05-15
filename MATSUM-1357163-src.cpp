#include <iostream>
#include <cstring>

using namespace std;

int Tree[1025][1025], M[1025][1025], n;

int read(int x, int y){
 int sum=0, y1;
 while(x>0){
  y1=y;
  while(y1>0){
   sum+=Tree[x][y1];
   y1-=(y1&-y1);
  }
  x-=(x&-x);
 }
 return sum;
}

void print(){
 for(int i=0; i<=n; i++){
  for(int j=0; j<=n; j++)
   cout<<Tree[i][j]<<" ";
  cout<<endl;
 }
}

int main(){
 int t, x, y, x1, y1, num;
 char query[4];
 scanf("%d", &t);
 while(t--){
  scanf("%d", &n);
  for(int i=0; i<=n; i++)
   for(int j=0; j<=n; j++){
    M[i][j]=0;
    Tree[i][j]=0;
   }
  while(1){
   scanf("%s", query);
   if(!strcmp(query, "END")){
    printf("\n");
    break;
   }
   else if(!strcmp(query, "SET")){
    scanf("%d%d%d", &x, &y, &num);
    x++; y++;
    x1=x; y1=y;
    while(x1<=n){
     y1=y;
     while(y1<=n){
      Tree[x1][y1]+=num-M[x][y];
      y1+=(y1&-y1);
     }
     x1+=(x1&-x1);
    }
    M[x][y]=num;
   }
   else{
    scanf("%d%d%d%d", &x, &y, &x1, &y1);
    x++; y++; x1++; y1++;
    printf("%d\n", read(x1, y1)-read(x-1, y1)+read(x-1, y-1)-read(x1, y-1));
   }
  }
 }
 return 0;
}
