#include <bits/stdc++.h>
using namespace std;

int getMatrixCost(std::vector<int> matrix, int n){
	int i,j,k,l,m;
	std::vector<std::vector<int> > dp (n+1, std::vector<int> (n+1,0));
	for(i=0;i<=n;i++){
		dp[i][i]=0;
	}
	for(l=2;l<n;l++){
		for(i=1;i<n-l+1;i++){
			j=i+l-1;
			dp[i][j]=INT_MAX;
			for(k=i;k<j;k++){
				dp[i][j]=min(dp[i][j], dp[i][k] + dp[k+1][j] + matrix[i-1]*matrix[k]*matrix[j]);
			}
		}
	}
	return dp[1][n-1];
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	std::vector<int> matrix;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>k;
		matrix.push_back(k);		
	}
	int totalCost = getMatrixCost(matrix, n);
	cout<<totalCost<<endl;
	return 0;
}