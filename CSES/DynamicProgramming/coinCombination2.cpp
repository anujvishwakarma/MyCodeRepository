#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	int MOD = 1e9+7;
	std::vector<int> coins;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>k;
		coins.push_back(k);
	}
	vector<vector<int> >dp(n+1, vector<int>(m+1,0));
	for(i=0;i<=n;i++){
		dp[i][0]=1;
	}
	for(i=1;i<=n;i++){
		for(j=0;j<=m;j++){
			if(j-coins[i-1] >=0){
				dp[i][j]+=(dp[i-1][j] % MOD + dp[i][j-coins[i-1]] %MOD) %MOD;
			}else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	cout<<dp[n][m]<<endl;
	return 0;
}