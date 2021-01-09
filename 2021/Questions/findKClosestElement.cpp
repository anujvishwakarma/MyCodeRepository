#include <bits/stdc++.h>
using namespace std;


int getPivot(std::vector<int> data, int value, int low, int high){
	if(data[high]<=value){
		return high;
	}
	else if (data[low]>=value){
		return low;
	}
	int mid = (low+high)/2;

	if(data[mid]<=value && data[mid+1]>value){
		return mid;
	}
	if(data[mid] < value){
		return getPivot(data, value, mid+1, high);
	}
	return getPivot(data, value, low, mid-1);
}

void printAllClosest(std::vector<int> &data, int n, int value, int k){
	int i,j;
	int pivot = getPivot(data, value, 0, n-1);
	int left = pivot;
	cout<<"Pibot is "<< left<<endl; 
	int right = pivot+1;
	int count =0;

	while(left>=0 && right<n && count <k){
		if(abs(value - data[left]) < abs(value - data[right])){
			cout<<data[left]<<" ";
			left--;
		}else{
			cout<<data[right]<<" ";
			right++;
		}
		count++;
	}

	while(left>=0 && count<k){
		cout<<data[left]<<" ";
		left--;
		count++;
	}

	while(right<n && count <k){
		cout<<data[right]<<" ";
		right++;
		count++;
	}
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	std::vector<int> data;
	cin>>n>>m>>l;
	for(i=0;i<n;i++){
		cin>>k;
		data.push_back(k);
	}
	printAllClosest(data, n, m, l);
	return 0;
}