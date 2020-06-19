#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	long long int i,x,y,n;
	multimap<pair<long long int, long long int>, long long int>myMap;

	priority_queue<pair<long long int, long long int>, std::vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>> > pq;
	
	cin>>n;
	std::vector<long long int> ans(n);
	for(i=0;i<n;i++){
		cin>>x>>y;
		myMap.insert(make_pair(make_pair(x,y),i));
	}

	pair<long long int, long long int> pairData;
	long long int curr_Index ;
	long long int rooms = 0;

	for(auto it=myMap.begin(); it!=myMap.end(); ++it){
		long long int room_number;
		pairData = it->first;
		curr_Index = it->second;
		if(pq.empty() || (pq.top().first >= pairData.first)){
			rooms++;
			room_number = rooms;
		}else{
			room_number = pq.top().second;
			pq.pop();
		}
		pq.push(make_pair(pairData.second, room_number));
		ans[curr_Index] = room_number;
	}
	cout<<rooms<<endl;
	for(i=0;i<n;i++){
		cout<<ans[i];
		if(i<n-1){cout<<" ";}
	}
	return 0;
}