#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	string s1,s2;
	cin>>s1>>s2;

	n = s1.length();
	m = s2.length();
	std::vector<std::vector<int>> dp(n+1, std::vector<int> (m+1));

	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			if(i==0 || j ==0){
				dp[i][j]=max(i,j);
			}
			else{
				if(s1[i-1]!=s2[j-1]){
					dp[i][j]=min(dp[i-1][j-1], min (dp[i-1][j], dp[i][j-1]));
					dp[i][j]++;
				}else{
					dp[i][j]=dp[i-1][j-1];
				}
			}
		}
	}

	cout<<dp[n][m]<<endl;
	return 0;
}