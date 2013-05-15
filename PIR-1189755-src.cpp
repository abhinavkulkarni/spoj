#include <iostream>
#include <cmath>

using namespace std;

int main(){
 int t;
 double W, U, V, w, u, v;
 long double vol;
 cin>>t;
 while(t--){
  cin>>u>>v>>w>>W>>V>>U;
  vol=sqrt(4*u*u*w*w*v*v-u*u*pow((long double)(v*v+w*w-U*U), 2)-v*v*pow((long double)(w*w+u*u-V*V), 2)-w*w*pow((long double)(u*u+v*v-W*W), 2)+(v*v+w*w-U*U)*(w*w+u*u-V*V)*(u*u+v*v-W*W))/12;
  printf("%.4Lf\n", vol);
 }
 return 0;
}
