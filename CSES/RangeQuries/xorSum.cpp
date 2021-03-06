#include <bits/stdc++.h>
using namespace std;

long long int constructTree(std::vector<long long int> &segmentTree, 
	std::vector<long long int> &data ,long long int low
	,long long int high, long long int treeIndex){
	if( low == high){
		segmentTree[treeIndex] = data[low];
		return data[low];
	}
	long long int mid = (low+high)/2;
	segmentTree[treeIndex] = constructTree(segmentTree, data, low, mid, 2*treeIndex+1)^
	constructTree(segmentTree, data, mid+1, high, 2*treeIndex+2);
	return segmentTree[treeIndex];
}

long long int getSum(vector<long long int> &segmentTree, long long int start,
	long long int end, long long int queryStart, long long int queryEnd,
	long long int treeIndex){
	if( queryStart> end || queryEnd < start) {
		return 0;
	}
	if(queryStart<=start && queryEnd>=end){
		return segmentTree[treeIndex];
	}
	long long int mid = (start + end)/2;
	return (getSum(segmentTree, start, mid, queryStart, queryEnd, 2*treeIndex+1)^
		getSum(segmentTree, mid+1, end, queryStart, queryEnd, 2*treeIndex+2));
}

int main(int argc, char const *argv[]){
	long long int i,j,k,l,m,n,q,x,y;
	cin>>n>>q;
	std::vector<long long int> data;
	for(i=0;i<n;i++){
		cin>>k;
		data.push_back(k);
	}
	vector<long long int> segmentTree(4*n,0);
	constructTree(segmentTree, data, 0, n-1, 0);
	while(q--){
		cin>>x>>y;
		x--;y--;
		cout<<getSum(segmentTree, 0 , n-1, x, y, 0)<<endl;
	}
	return 0;
}