#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	long long int i,j,k,l,m,n,x,y;
	cin>>n>>m;
	vector<long long int> data;
	std::vector<long long int> commSum(n+1,0);
	cin>>k;
	data.push_back(k);
	commSum[0]=k;
	for(i=1;i<n;i++){
		cin>>k;
		data.push_back(k);
		commSum[i]=commSum[i-1]+k;
	}
	while(m--){
		cin>>x>>y;
		x--;y--;
		long long int curr_sum = commSum[y]-commSum[x] + data[x];
		cout<<curr_sum<<endl;
	}
	return 0;
}