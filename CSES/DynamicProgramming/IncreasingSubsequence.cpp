#include <bits/stdc++.h>
using namespace std;

void print(vector<long long int> data, long long int length){
	cout<<"Length is "<<length<<endl;
	for(int i=0;i<data.size();i++){
		cout<<data[i]<<" ";
	}
	cout<<endl;
}


int main(int argc, char const *argv[]){
	long long int i,j,k,l,m,n;
	std::vector<long long int> data;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>k;
		data.push_back(k);
	}
	std::vector<long long int> dp(n,0);
	long long int length = 1;
	dp[0] = data[0];

	for(i=1;i<n;i++){
		auto it = lower_bound(dp.begin(), dp.begin()+length, data[i]);
		if(it == dp.begin()+length){
			dp[length]=data[i];
			length++;
		}else{
			*it=data[i];
		}
	//	print(dp,length);
	}
	cout<<length<<endl;
	return 0;
}