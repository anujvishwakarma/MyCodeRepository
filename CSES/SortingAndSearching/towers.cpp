#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	long long int i,j,k,n;
	std::vector<long long int> data;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>k;
		data.push_back(k);
	}
	multiset<int> mySet;
	multiset<int> :: iterator it;
	for(i=0;i<n;i++){
		it = mySet.lower_bound(data[i]+1);
		if(it == mySet.end()){
			mySet.insert(data[i]);
		}else{
			mySet.erase(it);
			mySet.insert(data[i]);
		}
	}
	cout<<mySet.size()<<endl;
	return 0;
}