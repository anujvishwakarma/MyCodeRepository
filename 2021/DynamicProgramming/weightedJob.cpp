#include <bits/stdc++.h>
using namespace std;

bool myComp(const pair<int,int> &a , const pair<int,int> &b){
	return a.second<b.second;
}

int getNonConflict(std::vector<pair<int,int>> jobTime,int currJobId,  int n){
	int i=currJobId-1;
	int jobId=-1;
	while(i>=0){
		if(jobTime[currJobId].first >= jobTime[i].second){
			jobId = i;
			break;
		}
		i--;
	}
	return jobId;
}

int getMax(std::vector<pair<int,int>> jobTime, 	std::vector<int> jobProfit, int n){
	int i,j;
	sort(jobTime.begin(), jobTime.end(), myComp);
	std::vector<int> dp(n+1,0);
	dp[0]=jobProfit[0];

	for(i=1;i<n;i++){
		int incl = jobProfit[i];
		int l = getNonConflict(jobTime,i, n);
		if(l!=-1){
			incl += dp[l];
		}
		dp[i]=max(incl, dp[i-1]);
	}
	return dp[n-1];
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	std::vector<pair<int,int>> jobTime;
	std::vector<int> jobProfit;
	cin>>n;
	int s,e,profit;
	for(i=0;i<n;i++){
		cin>>s>>e>>profit;
		jobTime.push_back(make_pair(s,e));
		jobProfit.push_back(profit);
	}
	int getMaxProfit = getMax(jobTime, jobProfit, n);
	cout<<getMaxProfit<<endl;
	return 0;
}