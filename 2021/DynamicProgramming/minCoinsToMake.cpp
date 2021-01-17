#include <bits/stdc++.h>
using namespace std;

int getMinCoins(std::vector<int> data, int n , int sum){
	int i,j,k;
	std::vector<int> dp(sum+1, INT_MAX);
	dp[0]=0;
	for(i=1;i<=sum;i++){
		for(j=0;j<n;j++){
			if(i>=data[j]){
				int curr_min = dp[i - data[j]];
				if(curr_min!=INT_MAX){
					dp[i] =  min(dp[i] , curr_min+1);
				}
			}
		}
	}
	return dp[sum];
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	cin>>n>>m;
	std::vector<int> data;
	for(i=0;i<n;i++){
		cin>>k;
		data.push_back(k);
	}
	int minCoins = getMinCoins(data, n, m);
	cout<<minCoins<<endl;
	return 0;
}