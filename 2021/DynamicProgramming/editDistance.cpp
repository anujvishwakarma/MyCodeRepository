#include <bits/stdc++.h>
using namespace std;

int getEditDistance(string s1, string s2, int n, int m){
	int i,j,k;
	std::vector<std::vector<int> > dp(n+1, std::vector<int> (m+1,0));
	for(i=1;i<=m;i++){
		dp[0][i]=i;
	}
	for(i=1;i<=n;i++){
		dp[i][0]=i;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j]=dp[i-1][j-1];
			}else{
				dp[i][j]=1+min( dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
			}
		}
	}
	return dp[n][m];
}

int main(int argc, char const *argv[]){
	int i,j,k,l,n,m;
	string s1,s2;
	cin>>s1>>s2;
	int value = getEditDistance(s1, s2, s1.length(), s2.length());
	cout<<value<<endl;
	return 0;
}