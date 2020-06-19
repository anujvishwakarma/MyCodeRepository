#include <bits/stdc++.h>
using namespace std;


int knapSack(int w[10],int v[10],int n,int bag){
	int dp[100][100],i,j;
	for(i=0;i<=n;i++){
		for(j=0;j<=bag;j++){
			if(i==0||j==0){
				dp[i][j]=0;
			}
			else if(w[i-1]<=bag){
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i-1]]+v[i-1]);
			}else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
   return dp[n][bag];
}


int main(int argc, char const *argv[]){
	int i,j,k,l,m,n,bag;
	int w[10000],cost[1000];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>w[i]>>cost[i];
	}
	cin>>bag;
	int ans = knapSack(w,cost,n,bag);
	cout<<ans<<endl;
	return 0;
}