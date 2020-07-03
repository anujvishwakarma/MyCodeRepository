#include <bits/stdc++.h>
using namespace std;

#define pii pair<long long int,long long int> 
int main(int argc, char const *argv[]){
	long long int i,j,k,l,m,n;
	vector<long long int> points;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>k;
		points.push_back(k);
	}
	vector<vector<pii>> dp(n, vector<pii>(n,{0,0}));
	for(i=0;i<n;i++){
		dp[0][0].first = points[i];
	}

	for(l=2;l<=n;l++){
		for(i=0;i<n-l+1;i++){
			j=i+l-1;
			long long int extremeLeft = points[i]+dp[i+1][j].second; 
			long long int extemeRight = points[j]+dp[i][j-1].second;

			if(extremeLeft > extemeRight){
				dp[i][j].first = extremeLeft;
				dp[i][j].second = dp[i+1][j].first; 
			}
			else{
				dp[i][j].first = extemeRight;
				dp[i][j].second = dp[i][j-1].first;
			}
		}
	}
	cout<<(dp[0][n-1].first)<<endl;
	return 0;
}