#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
int main(int argc, char const *argv[]){
	long long int i,j,k,l,m,n;
	cin>>n;
	std::vector<long long int> dp(n+1,0);
	for(i=0;i<=n;i++){
		if(i<=5){
			dp[i]=1;
		}
		for(j=i-6;j<i;j++){
			if(j>=0){
				dp[i]=(dp[j]%MOD+dp[i]%MOD)%MOD;
			}
		}
	}
	cout<<dp[n-1]<<endl;
	return 0;
}