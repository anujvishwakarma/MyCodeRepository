#include <bits/stdc++.h>
using namespace std;

int getMaxCut(string s, int n){
	int i,j,k,l;
	std::vector<std::vector<int> > dp(n+1, std::vector<int> (n+1));
	std::vector<std::vector<bool> > palin(n+1, std::vector<bool> (n+1, false));
	for(i=0;i<=n;i++){
		palin[i][i]=true;
		dp[i][i]=0;
	}
	for(l=2;l<=n;l++){
		for(i=0;i<n-l+1;i++){
			j=i+l-1;
			if(l==2){
				palin[i][j]=(s[i]==s[j]);
			}
			else{
				palin[i][j] = (s[i]==s[j]) && palin[i+1][j-1];
			}
			if(palin[i][j]){
				dp[i][j]=0;
			}else{
				dp[i][j]=INT_MAX;
				for(k=i;k<j;k++){
					dp[i][j]=min(dp[i][j], 1+dp[i][k] + dp[k+1][j]);
				}
			}
		}	
	}
	return dp[0][n-1];
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	string s;
	cin>>s;
	n = s.length();
	int maxCut = getMaxCut(s, n);
	cout<<maxCut<<endl;
	return 0;
}