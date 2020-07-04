#include <bits/stdc++.h>
using namespace std;

#define pll pair<long long int, long long int>

int main(int argc, char const *argv[]){
	long long int i,j,k,l,m,n;
	long long int start,end,profit;
	cin>>n;
	std::vector<pair<long long int, pll> > data(n);
	std::vector<long long int> dp(n);
	for(i=0;i<n;i++){
		cin>>start>>end>>profit;
		data[i] = make_pair(end, make_pair(start,profit));
	}

	sort(data.begin(), data.end());
	dp[0]=data[0].second.second;

	for(i=1;i<n;i++){
		long long int end = data[i].first;
		long long int start = data[i].second.first;
		long long int curr_profit = data[i].second.second;

		long long int index = lower_bound(data.begin(), data.end(), 
			make_pair(start, make_pair((long long int)0,(long long int)0)) ) 
		- data.begin() - 1;

		//cout<<"start --> "<<start<<" and End "<<end<<endl;
		//cout<<"Index is -> "<<index<<endl;

		long long int previousProfit = dp[i-1];
		if(index>=0){
			previousProfit = max(previousProfit, dp[index] + curr_profit);
		}else{
			previousProfit = max(previousProfit, curr_profit);
		}
		dp[i] = previousProfit;
	}
	cout<<dp[n-1]<<" ";
	return 0;
}