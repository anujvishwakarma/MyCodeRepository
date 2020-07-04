#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	int sum,mod = 1e9+7;
	cin>>n;
	sum = (n)*(n+1)/2;
	if(sum%2){
		cout<<"0"<<endl;
		return 0;
	}
	sum/=2;

	std::vector<std::vector<int>> dp(n, std::vector<int> (sum+1,0));
	dp[0][0]=1;
	for(i=1;i<n;i++){
		for(j=0;j<=sum;j++){
			if(j>=i){
				dp[i][j]=(dp[i-1][j]+dp[i-1][j-i])%mod;
			}else{
				dp[i][j]=dp[i-1][j]%mod;
			}
		}
	}
	cout<<dp[n-1][sum]<<endl;
	return 0;
}