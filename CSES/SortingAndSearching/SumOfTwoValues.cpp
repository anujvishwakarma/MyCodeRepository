#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
	long long int i,j,n,m,k, curr_value;
	std::vector<pair<long long int, long long int>> data;
	cin>>n>>k;
	for(i=0;i<n;i++){
		cin>>m;
		data.push_back(make_pair(m,i+1));
	}
	sort(data.begin(), data.end());
	i=0, j=n-1;
	bool flag = false;
	while(i<j){
		curr_value = data[i].first+data[j].first;
		if( curr_value == k){
			cout<<min(data[i].second,data[j].second)<<" "<<max(data[i].second,data[j].second)<<endl;
			flag = true;
			break;
		}
		else if(curr_value>k){
			j--;
		}else{
			i++;
		}
	}
	if(!flag){
		cout<<"IMPOSSIBLE"<<endl;
	}
	return 0;
}