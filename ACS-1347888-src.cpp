#include <iostream>

using namespace std;

main(){
 int i, j, x, y, z, rows[1234], cols[5678];
 char c;
 for(i=0; i<1234; i++)
  rows[i]=i;
 for(i=0; i<5678; i++)
  cols[i]=i;
 while(cin>>c){
  switch(c){
   case 'R':
    scanf("%d%d", &x, &y);
    i=rows[x-1];
    rows[x-1]=rows[y-1];
    rows[y-1]=i;
    break;
   case 'C':
    scanf("%d%d", &x, &y);
    i=cols[x-1];
    cols[x-1]=cols[y-1];
    cols[y-1]=i;
    break;
   case 'Q':
    scanf("%d%d", &x, &y);
    printf("%d\n", rows[x-1]*5678+cols[y-1]+1);
    break;
   case 'W':
    scanf("%d", &z);
    x=(z-1)/5678;
    y=(z-1)%5678;
    for(i=0; rows[i]!=x; i++);
    for(j=0; cols[j]!=y; j++);
    printf("%d %d\n", i+1, j+1);
    break;
  }
 }
}
