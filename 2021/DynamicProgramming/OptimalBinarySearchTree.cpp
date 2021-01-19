#include <bits/stdc++.h>
using namespace std;

int getFreq(std::vector<pair<int,int>> data, int s, int e){
	int i;
	int ans=0;
	for(i=s;i<=e;i++){
		ans+=data[i].second;
	}
	return ans;
}

int getMinCost(std::vector<pair<int,int>> data, int n){
	int i,j,k,l;
	std::vector<std::vector<int> >dp(n, std::vector<int> (n,0));
	for(i=0;i<n;i++){
		dp[i][i]=data[i].second;
	}
	for(l=2;l<=n;l++){
		for(i=0;i<n-l+1;i++){
			j=i+l-1;
			dp[i][j]=INT_MAX;
			for(k=i;k<=j;k++){
				int curr_cost = ((k>i) ? dp[i][k-1] : 0) + (k<j ? dp[k+1][j]:0)+getFreq(data,i,j);
				dp[i][j]=min(dp[i][j], curr_cost);
			}
		}
	}
	return dp[0][n-1];
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	std::vector<pair<int,int>> data;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>k>>l;
		data.push_back(make_pair(k,l));
	}

	int minCost = getMinCost(data, n);
	cout<<minCost<<endl;
	return 0;
}