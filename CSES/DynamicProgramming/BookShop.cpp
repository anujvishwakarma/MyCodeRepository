#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	int i,j,k,l,n,m;
	std::vector<pair<int,int>> data;
	cin>>n>>m;
	std::vector<std::vector<int>> dp(n+1, std::vector<int> (m+1, 0));
	int x,y;
	for(i=0;i<n;i++){
		cin>>x;
	    data.push_back(make_pair(x,0));
	}
	for(i=0;i<n;i++){
		cin>>y;
		data[i].second = y;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(data[i-1].first <= j){
				dp[i][j] = max(dp[i-1][j], 
					data[i-1].second + dp[i-1][j-data[i-1].first]);
			}else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	cout<<dp[n][m]<<endl;
	return 0;
}