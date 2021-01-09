#include <bits/stdc++.h>
using namespace std;

void merge(std::vector<int> &v, int low, int mid, int high){
	int i,j,k;
	std::vector<int> first, second;
	int n1= mid - low +1;
	int n2 = high - mid;

	for(i=0;i<n1;i++){
		first.push_back(v[low+i]);
	}
	for(i=0;i<n2;i++){
		second.push_back(v[mid+1+i]);
	}
	i=0,j=0,k=low;
	while(i<n1 && j<n2){
		if(first[i]<second[j]){
			v[k] = first[i];
			i++;
			k++;
		}else{
			v[k]=second[j];
			j++;k++;
		}
	}
	while(i<n1){
		v[k] = first[i];
		i++;
		k++;
	}
	while(j<n2){
		v[k]=second[j];
		j++;
		k++;
	}
}

void mergeSort(std::vector<int> &v, int low, int high){
	if(low<high){
		int mid = (low+high)/2;
		mergeSort(v, low, mid);
		mergeSort(v, mid+1, high);
		merge(v, low, mid, high);
	}
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	vector<int> input;
	cin>>n;
	for(i=0;i<n;i++) {
		cin>>k;
		input.push_back(k);
	}
	mergeSort(input, 0, n-1);
	for(i=0;i<n;i++){
		cout<<input[i]<<" "; 
	}
	return 0;
}