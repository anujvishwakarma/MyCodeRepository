#include <bits/stdc++.h>
using namespace std;

int getTotalWays(std::vector<int> coins, int coinSize, int sum){
	int i,j;
	std::vector<std::vector<int> > dp(coinSize+1, std::vector<int> (sum+1,0));
	for(i=0;i<=sum;i++){
		dp[0][i]=0;
	}
	for(i=0;i<coinSize;i++){
		dp[i][0]=1;
	}
	for(i=1;i<=coinSize;i++){
		for(j=1;j<=sum;j++){
			if(j>= coins[i-1]){
				dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
			}else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	return dp[coinSize][sum];
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n,sum;
	std::vector<int> coins;
	cin>>n>>sum;
	for(i=0;i<n;i++){
		cin>>k;
		coins.push_back(k);
	}
	int totalWays = getTotalWays(coins, n, sum);
	cout<<totalWays<<endl;
	return 0;
}