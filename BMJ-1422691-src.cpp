#include <iostream>

using namespace std;

int main(){
	int n, r, num, x, y;
	while(cin>>n)
	{
		r=1;
		while(n-1>3*r*(r-1))r++;
		r--;
		num=3*r*(r+1)+1;
		if(num==n){
			cout<<r<<" 0"<<endl;
			continue;
		}
		if(num-r<=n)
		{
			cout<<r<<" -"<<num-n<<endl;
			continue;
		}
		num-=r;
		if(num-r+1<=n)
		{
			cout<<r-num+n<<" -"<<r<<endl;
			continue;
		}
		num-=r;
		if(num==n)
		{
			cout<<"0 -"<<r<<endl;
			continue;
		}
		if(num-r+1<=n)
		{
			cout<<"-"<<num-n<<" -"<<r-(num-n)<<endl;
			continue;
		}
		num-=r;
		if(num-r<=n)
		{
			cout<<"-"<<r<<" "<<num-n<<endl;
			continue;
		}
		num-=r;
		if(num-r+1<=n)
		{
			cout<<"-"<<r-(num-n)<<" "<<r<<endl;
			continue;
		}
		num-=r;
		if(num-r+1<=n)
		{
			cout<<num-n<<" "<<r-(num-n)<<endl;
			continue;
		}
	}
	return 0;
}
