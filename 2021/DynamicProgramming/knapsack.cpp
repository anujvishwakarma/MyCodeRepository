#include <bits/stdc++.h>
using namespace std;

int getMaxProfit(std::vector<int> weight, std::vector<int> values, int n , int bag)	{
	int i,j,k;
	vector<std::vector<int> > dp(n+1, std::vector<int> (bag+1, 0));
	for(i=1;i<=n;i++){
		for(j=1;j<=bag;j++){
			if(j>=weight[i-1]){
				dp[i][j]= max(dp[i-1][j], values[i-1] + dp[i-1][j-weight[i-1]]);
			}else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	return dp[n][bag];
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	std::vector<int> weight;
	std::vector<int> values;
	int bag;
	cin>>n>>bag;
	for(i=0;i<n;i++){
		cin>>k;
		weight.push_back(k);
	}
	for(i=0;i<n;i++){
		cin>>k;
		values.push_back(k);
	}
	int max_profit = getMaxProfit(weight, values, n, bag);
	cout<<max_profit<<endl;
	return 0;
}