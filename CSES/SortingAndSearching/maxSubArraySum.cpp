#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	long long int i,j,k,l,m,n;
	std::vector<long long int> data;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>k;
		data.push_back(k);
	}
	long long int max_curr = data[0], ans = data[0];
	for(i=1;i<n;i++){
		max_curr = max(max_curr+data[i], data[i]);
		ans = max(ans, max_curr);
	}
	cout<<ans<<endl;
	return 0;
}