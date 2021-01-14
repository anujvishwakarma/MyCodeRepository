#include <bits/stdc++.h>
using namespace std;


int getMaxProfit(std::vector<int> cuts, std::vector<int> profit, int n, int rodLength){
	int i,j;
	std::vector<std::vector<int> > dp(n+1, std::vector<int> (rodLength+1, 0));
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(j>=cuts[i-1]){
				dp[i][j]=max(dp[i-1][j], profit[i-1] + dp[i][j- cuts[i-1]]);
			}else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	return dp[n][rodLength];
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	std::vector<int> cuts;
	std::vector<int> profit;
	int rodLength;
	cin>>n>>rodLength;
	for(i=0;i<n;i++){
		cin>>k;
		cuts.push_back(k);
	}
	for(i=0;i<n;i++){
		cin>>k;
		profit.push_back(k);
	}
	int maxProfit = getMaxProfit( cuts, profit, n, rodLength);
	cout<<maxProfit<<endl;
	return 0;
}