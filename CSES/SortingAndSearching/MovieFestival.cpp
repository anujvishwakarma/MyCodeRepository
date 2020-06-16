#include <bits/stdc++.h>
using namespace std;
 
bool comp(pair<long long int, long long int> &a, 
	pair<long long int, long long int> &b){
	return a.second < b.second;
}

int main(int argc, char const *argv[]){
	long long int i,x,y,n, ans =1;
	std::vector<pair<long long int, long long int>> data;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>x>>y;
		data.push_back(make_pair(x,y));
	}
	sort(data.begin(), data.end(), comp);
	long long int curr_ans = 1;
	long long int curr_finishTime = data[0].second;
	for(i=1;i<n;i++){
		if(data[i].first>=curr_finishTime){
			curr_ans++;
			curr_finishTime = data[i].second;
		}
		ans=max(ans, curr_ans);
	}
	cout<<ans<<endl;
	return 0;
}