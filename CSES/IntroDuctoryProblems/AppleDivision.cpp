#include <bits/stdc++.h>
using namespace std;

long long int minDiff=INT_MAX;
vector<vector<long long int>> allPermutations;

void evaluateData(std::vector<long long int > v, long long int sum){
	long long int i, size = v.size(), curr_sum=0, rest_sum=sum;
	for(i=0;i<size;i++){
		curr_sum+=v[i];
		rest_sum-=v[i];
		minDiff=min(minDiff, abs(rest_sum - curr_sum));
	}
}

void getAllPermutations(std::vector<long long int> v,
 long long int low, long long int high, long long int sum){
	if(low == high){
		vector<long long int> temp = v;
		evaluateData(temp, sum);
		return;
	}
	long long int index;
	for(index=low; index<=high; index++){
		swap(v[low], v[index]);
		getAllPermutations(v, low+1, high, sum);
		swap(v[low],v[index]);
	}
}

int main(int argc, char const *argv[]){
	long long int i,n,k, sum=0;
	std::vector<long long int> v;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>k;
		sum+=k;
		v.push_back(k);
	}
	getAllPermutations(v, 0 , n-1, sum);
	cout<<minDiff<<endl;
	return 0;
}