#include<bits/stdc++.h>
using namespace std;

int getIndex(std::vector<int> v, int low, int high){
	if(low<=high){
		int mid=(low+high)/2;
		if(low<mid && v[mid]==1 && v[mid-1]==0){
			return mid;
		}
		else if(mid<high && v[mid]==0 && v[mid+1]==1){
			return mid+1;
		}
		if(mid==low && v[mid]==1){
			return mid;
		}
		if(v[mid]==1)return getIndex(v,low,mid-1);
		return getIndex(v,mid+1,high);
	}
	return -1;
}

int main(int argc, char const *argv[]){
	int i,j,k,m,n;
	cin>>n;
	std::vector<int> v;
	for(i=0;i<n;i++){
		cin>>k;
		v.push_back(k);
	}
	int index=getIndex(v,0,n-1);
	if(index==-1){
		cout<<"0"<<endl;
		return 1;
	}
	cout<<(n-index)<<endl;
	return 0;
}