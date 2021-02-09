#include <bits/stdc++.h>
using namespace std;

void input(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

int querySum(std::vector<int> &segmentTree, int start, int end, int treeIndex, int qs, int qe){
	if(qs > end || qe < start){
		return 0;
	}
	if(qs<=start && qe>=end){
		return segmentTree[treeIndex];
	}
	int mid  = (start+end)/2;
	return querySum(segmentTree, start, mid, 2*treeIndex+1, qs, qe) + 
	querySum(segmentTree, mid+1, end, 2*treeIndex+2, qs, qe);
}

int constructTree(std::vector<int> &segmentTree,  std::vector<int> &data, int low, int high, int treeIndex){
	if(low == high){
		segmentTree[treeIndex] = data[low];
		return data[low];
	}
	int mid = (low+high)/2;
	int curr_sum = constructTree(segmentTree, data, low, mid, 2*treeIndex+1) + 
	constructTree(segmentTree, data, mid+1, high , 2*treeIndex+2);
	segmentTree[treeIndex] = curr_sum;
	return segmentTree[treeIndex];
}

int main(int argc, char const *argv[]){
	input();
	int i,j,k,l,m,n;
	cin>>n;
	std::vector<int> data;
	for(i=0;i<n;i++){
		cin>>k;
		data.push_back(k);
	}
	std::vector<int> segmentTree(4*n,0);
	constructTree(segmentTree, data, 0, n-1, 0);
	int q,x,y;
	cin>>q;
	while(q--){
		cin>>x>>y;
		x--;y--;
		int ans = querySum(segmentTree, 0, n-1, 0, x, y);
		cout<<ans<<endl;
	}
	return 0;
}