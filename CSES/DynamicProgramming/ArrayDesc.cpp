#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	int mod = 1e9+7;
	int i,j,x,k,l,m,n,ans =0;
	cin>>n>>m;
	std::vector<std::vector<int> > dp(n, std::vector<int> (m+1,0));
	cin>>k;
	if(k==0){
		fill(dp[0].begin(), dp[0].end(),1);
	}else{
		dp[0][k]=1;
	}
	for(i=1;i<n;i++){
		cin>>x;
		if(x==0){
			for(j=1;j<=m;j++){
				for(int k : {j-1, j ,j +1 }){
					if(k>=1 && k<=m){
						dp[i][j]+=dp[i-1][k];
						dp[i][j]%=mod;
					}
				}
			}
		}else{
			for(int k : {x-1, x ,x +1 }){
					if(k>=1 && k<=m){
						dp[i][x]+=dp[i-1][k];
						dp[i][x]%=mod;
					}
				}
		}
	}

	for(j=1;j<=m;j++){
		ans= (ans+dp[n-1][j])%mod;
	}
	cout<<ans<<endl;
	return 0;
}