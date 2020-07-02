#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	int mod = 1e9+7;
	std::vector<string> v;
	cin>>n;
	std::vector<std::vector<int> > dp(n, std::vector<int> (n, 0));
	string temp;
	for(i=0;i<n;i++){
		cin>>temp;
		v.push_back(temp);
	}

	bool flag = false;
	if(v[0][0]=='*'){
		cout<<"0"<<endl;
		return 0;
	}else{
		dp[0][0]=1;
	}

	for(i=1;i<n;i++){
		if(v[0][i]=='*'){
			dp[0][i]=-1;
			flag = true;
		}
		if(flag){
			dp[0][i]=-1;
		}else{
			dp[0][i]=1;
		}
	}

	flag = false;
	for(i=1;i<n;i++){
		if(v[i][0]=='*'){
			dp[i][0]=-1;
			flag = true;
		}
		if(flag){
			dp[i][0]=-1;
		}else{
			dp[i][0]=1;
		}
	}

	for(i=1;i<n;i++){
		for(j=1;j<n;j++){
			if(v[i][j]=='*'){
				dp[i][j]=-1;
			}
			else if(dp[i-1][j]==-1 && dp[i][j-1]==-1){
				dp[i][j]=-1;
			}
			else if(dp[i-1][j]==-1){
				dp[i][j]=dp[i][j-1];
			}
			else if(dp[i][j-1]==-1){
				dp[i][j]=dp[i-1][j];
			}
			else{
				dp[i][j]=(dp[i-1][j] % mod+dp[i][j-1] % mod ) % mod;
			}
		}
	}
/*
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/


	cout<<((dp[n-1][n-1]>=0)? dp[n-1][j-1] : 0)<<endl;
	return 0;

}