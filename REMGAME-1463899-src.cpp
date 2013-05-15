#include <iostream>

using namespace std;

int m[6][6];

int main(){
    int t, xorr;
    cin>>t;
    while(t--)
    {
              xorr=0;
              for(int i=0; i<5; i++)
              {
                      m[i][5]=0;
                      for(int j=0; j<5; j++)
                      {
                              cin>>m[i][j];
                              m[i][5]+=m[i][j];          
                      }
                      xorr^=m[i][5];
              }
              if(!xorr)
              {
                      printf("losing\n");
                      continue;        
              }
              xorr=0;
              for(int j=0; j<5; j++)
              {
                      m[5][j]=0;
                      for(int i=0; i<5; i++)
                              m[5][j]+=m[i][j];
                      xorr^=m[5][j];
              }
              if(!xorr)
                      printf("losing\n");
              else
                  printf("winning\n");
    }
    return 0;    
}
