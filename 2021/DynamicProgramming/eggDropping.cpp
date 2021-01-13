#include <bits/stdc++.h>
using namespace std;


int getCount(int egg, int floors){
	int i,j,k;
	std::vector<std::vector<int> > dp(egg+1, std::vector<int> (floors+1));
	int sep;
	for(i=0;i<=egg;i++){
		dp[i][0]=0;
		dp[i][1]=1;
	}

	for(i=1;i<=floors;i++){
		dp[1][i]=i;
	}
	int res;
	for(i=2;i<=egg;i++){
		for(j=2;j<=floors;j++){
			dp[i][j]=INT_MAX;
			for(sep = 1; sep<=j ; sep++){
				res = 1 + max(dp[i-1][sep-1], dp[i][j-sep]);
				dp[i][j] = min (dp[i][j], res);
			}
		}
	}
	return dp[egg][floors];
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	int egg,floors;
	cin>>egg>>floors;
	int tries = getCount(egg, floors);
	cout<<tries<<endl;
	return 0;
}