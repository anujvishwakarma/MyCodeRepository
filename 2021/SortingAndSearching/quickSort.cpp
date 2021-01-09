#include <bits/stdc++.h>
using namespace std;

int getPivot(std::vector<int> &data, int low, int high){
	int pivotElement = data[high];
	int i = low - 1;
	for(int j=low; j<high ; j++){
		if(data[j] < pivotElement){
			i++;
			swap(data[j], data[i]);
		}
	}
	swap(data[i+1], data[high]);
	return i+1;
}

void quickSort(std::vector<int> &v, int low, int high){
	if(low<high){
		int pivot = getPivot(v, low, high);
		quickSort(v, low, pivot - 1);
		quickSort(v, pivot + 1, high);
	}
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	std::vector<int> input;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>k;
		input.push_back(k);
	}
	quickSort(input, 0, n-1);
	for(i=0;i<n;i++){
		cout<<input[i]<<" "; 
	}
	return 0;
}