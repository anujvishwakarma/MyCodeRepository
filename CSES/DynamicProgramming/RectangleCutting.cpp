#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	cin>>n>>m;
	k = max(n,m);
	std::vector<std::vector<int> > dp(k+1, std::vector<int> (k+1, 0));
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			if(i==j){
				dp[i][j]=0;
			}
			else{
				dp[i][j]=1e9;
				for(k=1;k<i;k++){
					dp[i][j]=min(dp[i][j], 1+ dp[k][j] + dp[i-k][j]);
				}
				for(k=1;k<j;k++){
					dp[i][j]=min(dp[i][j], 1+dp[i][k]+dp[i][j-k]);
				}
			}
		}	
	}
	cout<<dp[n][m]<<endl;
	return 0;
}