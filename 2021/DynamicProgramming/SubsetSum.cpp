#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(std::vector<int> data, int n, int sum){
	int i,j;
	std::vector<std::vector<bool> > dp(n+1, std::vector<bool> (sum+1,false));
	for(i=0;i<=n;i++){
		dp[i][0]=true;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=sum;j++){
			if(j<data[i-1]){
				dp[i][j] = dp[i-1][j];
			}else{
				dp[i][j] = dp[i-1][j] || dp[i-1][j - data[i-1]];
			}
		}
	}
	return dp[n][sum];
}

int main(int argc, char const *argv[]){
	int i,j,k,m,n;
	std::vector<int> values;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>k;
		values.push_back(k);
	}
	bool isExist = isSubsetSum(values, n, m);
	cout<< isExist <<endl;
	return 0;
}