#include <bits/stdc++.h>
using namespace std;


bool searchBin(std::vector<int> v, int low, int high, int data){
	int mid;
	while(low<=high){
		mid = (low+high)/2;
		if(v[mid]==data){
			return true;
		}
		else if(v[mid]>data){
			high = mid -1;
		}
		else{
			low = mid+1;
		}
	}
	return false;
}


int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	vector<int> v;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>k;
		v.push_back(k);
	}

	bool isFound = searchBin(v, 0, n-1, m);
	cout<<isFound<<endl;
	return 0;
}