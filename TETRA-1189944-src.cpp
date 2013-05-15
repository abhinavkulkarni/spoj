#include <iostream>
#include <cmath>

using namespace std;

int main(){
 int t;
 double W, U, V, w, u, v;
 long double vol, S, r;
 cin>>t;
 while(t--){
  cin>>u>>v>>w>>W>>V>>U;
  vol=sqrt(4*u*u*w*w*v*v-u*u*pow((long double)(v*v+w*w-U*U), 2)-v*v*pow((long double)(w*w+u*u-V*V), 2)-w*w*pow((long double)(u*u+v*v-W*W), 2)+(v*v+w*w-U*U)*(w*w+u*u-V*V)*(u*u+v*v-W*W))/12;
  S=0;
  S+=sqrt((U+V+W)*(W+V-U)*(U+W-V)*(U+V-W))/4;
  S+=sqrt((U+v+w)*(U+v-w)*(U+w-v)*(v+w-U))/4;
  S+=sqrt((u+v+W)*(u+v-W)*(u+W-v)*(W+v-u))/4;
  S+=sqrt((u+w+V)*(u+w-V)*(u+V-w)*(w+V-u))/4;
  r=3*vol/S;
  printf("%.4Lf\n", r);
 }
 return 0;
}
