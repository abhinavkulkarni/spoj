#include <iostream>

using namespace std;

int DP[13][99];

int main(){
	int t, n, k, kk;
	for(n=0; n<13; n++)
		for(k=0; k<99; k++)
			DP[n][k]=0;
	for(n=1; n<13; n++)
		DP[n][0]=1;
	for(n=1; n<13; n++)
	{
		for(k=1; k<n; k++)
			DP[n][k]=DP[n-1][k]+DP[n][k-1];
		for(k=n; k<=n*(n-1)/2; k++)
			for(kk=k; kk>=k-n+1; kk--)
				DP[n][k]+=DP[n-1][kk];
		for(k=n*(n-1)/4+1; k<=n*(n-1)/2; k++)
			DP[n][k]=DP[n][n*(n-1)/2-k];
	}
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		cout<<DP[n][k]<<endl;
	}
}
