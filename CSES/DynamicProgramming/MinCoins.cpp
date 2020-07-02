#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	long long int i,j,k,m,n;
	std::vector<long long int> coin;
	cin>>n>>m;
	std::vector<long long int> dp(m+1,1e9);
	for(i=0;i<n;i++){
		cin>>k;
		coin.push_back(k);
	}
	dp[0]=0;
	for(i=1;i<=m;i++){
		for(j=0;j<n;j++){
			if(i-coin[j]>=0){
				dp[i]=min(dp[i], 1+dp[i-coin[j]]);
			}
		}
	}
	long long int ans;
	ans = (dp[m]== 1e9 ) ? -1 : dp[m];
	cout<<ans<<endl;
	return 0;
}