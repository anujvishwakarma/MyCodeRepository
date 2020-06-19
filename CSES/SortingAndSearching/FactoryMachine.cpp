#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	long long int i,j,k,m,n;
	cin>>n>>m;
	std::vector<long long int> data;
	priority_queue<pair<long long int,long long int> ,
	std::vector<pair<long long int,long long int>>, 
	greater< pair<long long int, long long int> > > pq;
	
	for(i=0;i<n;i++){
		cin>>k;
		data.push_back(k);
		pq.push(make_pair(k,k));
	}
	long long int ans = 0;
	while(m--){
		pair<long long int, long long int> currProduct = pq.top();
		pq.pop();
		ans = max(ans, currProduct.first);
		pq.push(make_pair(currProduct.first+currProduct.second,currProduct.second));
	}
	cout<<ans<<endl;
	return 0;
}