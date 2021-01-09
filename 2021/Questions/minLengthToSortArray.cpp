#include <bits/stdc++.h>
using namespace std;

pair<int,int> getAnswer(std::vector<int> &data, int n){
	int i, start =0, end = n-1;
	pair<int,int> ans;
	while(start<n-1){
		if(data[start]>data[start+1]){
			break;
		}
		start++;
	}
	if(start == n-1){
		return {-1,-1};
	}
	while(end>0){
		if(data[end]<data[end-1]){
			break;
		};
		end--;
	}
	int min_value = data[start];
	int max_value = data[end];
	for(i=start;i<=end;i++){
		min_value = min (min_value, data[i]);
		max_value = max (max_value, data[i]);
	}
	for(i=0;i<=start;i++){
		if(data[i]>min_value){
			start = i;
			break;
		}
	}
	for(i=n-1;i>=end;i--){
		if(data[i]<max_value){
			end=i;
			break;
		}
	}
	ans.first = start;
	ans.second = end;
	return ans;
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	vector<int> data;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>k;
		data.push_back(k);
	}
	pair<int,int> ans = getAnswer(data , n);
	cout<<ans.first<<" "<<ans.second<<endl;
	return 0;
}