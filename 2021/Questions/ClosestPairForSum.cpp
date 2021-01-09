#include <bits/stdc++.h>
using namespace std;

pair<int,int> getClosest(std::vector<int> &data1, vector<int> &data2, int value, int n, int m){
	int low = 0;
	int high = m-1;
	int diff = INT_MAX;
	pair<int,int> ans;
	while(low<n && high>=0){
		int tempValue = abs(data1[low] + data2[high] - value);
		if(tempValue < diff){
			diff = tempValue;
			ans.first = data1[low];
			ans.second = data2[high];
		}
		if(data1[low] + data2[high] > value){
			high--;
		}
		else{
			low++;
		}
	}
	return ans;
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n,value;
	std::vector<int> data1;
	std::vector<int> data2;
	cin>>n>>m>>value;
	for(i=0;i<n;i++){
		cin>>k;
		data1.push_back(k);
	}
	for(i=0;i<m;i++){
		cin>>k;
		data2.push_back(k);
	}
	pair<int,int> ans = getClosest(data1, data2, value, n, m);
	cout<<ans.first <<" "<<ans.second<<endl;
	return 0;
}