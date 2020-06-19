#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	long long int i,j,k,l,m,n, ans=1;
	std::vector<long long int> data;
	map<long long int, long long int> myMap;
	map<long long int, long long int> :: iterator it;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>k;
		data.push_back(k);
	}
	j=0,i=0;
	while(i<n){
		it= myMap.find(data[i]);
		if(it!=myMap.end()){
			ans = max(ans,abs(j-i));
			while(data[j]!=data[i]){
				myMap.erase(data[j]);
				j++;
			}
			j++;
		}
		myMap.insert(make_pair(data[i],i));
		i++;
	}
	cout<<max(ans, abs(j-i))<<endl;
	return 0;
}