#include <bits/stdc++.h>
using namespace std;

int getPalindromicSubsequence(string s){
	int i,j,k,l,m,n;
	n = s.length();
	std::vector<std::vector<int>> dp( n+1, std::vector<int> (n+1, 0));

	for(i=0;i<=n;i++){
		dp[i][i]=1;
	}

	for(l=2;l<=n;l++){
		for(i=0; i<n-l+1;i++){
			j=i+l-1;

			if(s[i]==s[j] && l==2){
				dp[i][j]=2;
			}
			else if(s[i]==s[j]){
				dp[i][j]= 2+ dp[i+1][j-1];
			}
			else {
				dp[i][j]=max(dp[i][j-1], dp[i+1][j]);
			}
		}
	}
	return dp[0][n-1];
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	string s1;
	cin>>s1;
	int ans = getPalindromicSubsequence(s1);
	cout<<ans<<endl;
	return 0;
}