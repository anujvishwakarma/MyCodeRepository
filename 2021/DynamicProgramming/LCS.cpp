#include <bits/stdc++.h>
using namespace std;

int LCS(string s1, string s2, int n, int m){
	int i,j,k,l;
	vector<std::vector<int> > dp(n+1, vector<int> (m+1,0));
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j]=1+dp[i-1][j-1];
			}else{
				dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[n][m];
}

int main(int argc, char const *argv[]){
	int i,j,k,l,n,m;
	string s1, s2;
	cin>>s1>>s2;
	int length = LCS(s1, s2, s1.length(), s2.length());
	cout<<length<<endl;
	return 0;
}