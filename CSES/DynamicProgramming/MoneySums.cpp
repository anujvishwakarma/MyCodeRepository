#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	std::vector<int> coins;
	set<int> ans;
	int sum =0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>k;
		sum+=k;
		coins.push_back(k);
	}
	vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
	for(i=1;i<=n;i++){
		for(j=1;j<=sum;j++){

			//cout<<"i -> "<<i<<" j-->"<< j<<" coins--> "<<coins[i-1]<<endl; 
			if(j==coins[i-1]){
				dp[i][j]=true;
			}
			else if(j>coins[i-1]){
				dp[i][j]=dp[i-1][j] || dp[i-1][j-coins[i-1]];
			}else{
				dp[i][j]=dp[i-1][j];
			}
			if(dp[i][j]){
				ans.insert(j);
			}
		}
	}

	cout<<ans.size()<<endl;
	for(auto it=ans.begin(); it!=ans.end(); ++it){
		cout<<*it<<" ";
	}
	return 0;
}