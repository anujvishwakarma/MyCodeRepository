#include <bits/stdc++.h>
using namespace std;

vector<int> getFactors(int value){
	std::vector<int> ans;
	int k;
	while(value){
		k = value%10;
		if(k>0){
			ans.push_back(k);
		}
		value = value/10;
	}
	return ans;
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	cin>>n;
	std::vector<int> dp(n+1,INT_MAX);
	dp[0]=0;

	for(i=1;i<=n;i++){
		if(i<=9){
			dp[i]=1;
		}else{
			vector<int> factors = getFactors(i);
			for(j=0;j<factors.size();j++){
				dp[i]=min(dp[i], dp[i-factors[j]]);
			}
			dp[i]+=1;
		}
	}

	cout<<dp[n]<<endl;
	return 0;
}