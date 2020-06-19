#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	int a[10000];
	int dp[10000];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	if(a[0]==0){
		cout<<"-1";
	}else{
		dp[0]=0;
		for(i=1;i<n;i++){
			dp[i]=INT_MAX;
			for(j=0;j<i;j++){
				if(j+a[j]>=i && dp[j]!=INT_MAX){
					dp[i]=min(dp[i],1+dp[j]);
				}
			}
		}
	}
	if(dp[n-1]==INT_MAX){
		cout<<"-1"<<endl;
	}else{
		cout<<dp[n-1]<<endl;
	}
	return 0;
}
