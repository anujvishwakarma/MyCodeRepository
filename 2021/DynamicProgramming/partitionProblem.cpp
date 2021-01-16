#include <bits/stdc++.h>
using namespace std;


bool partition(std::vector<int>  data, int n, int sum){
	int i,j;
	std::vector<std::vector<bool> > dp(n+1, std::vector<bool> (sum+1,false));
	for(i=0;i<=n;i++){
		dp[0][i]=true;
	}

	for(i=1;i<=n;i++){
		for(j=1;j<=sum;j++){
			if(j>=data[i-1]){
				dp[i][j]= dp[i][j] || dp[i-1][j-data[i-1]];
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][sum];
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	int sum;
	std::vector<int> data;
	cin>>n>>sum;
	int curr_sum=0;
	for(i=0;i<n;i++){
		cin>>k;
		curr_sum+=k;
		data.push_back(k);
	}
	if(curr_sum%2 == 1){
		cout<<"false"<<endl;
		return 0;
	}
	bool isPossible = partition(data, n, curr_sum);
	cout<<isPossible<<endl;
	return 0;
}