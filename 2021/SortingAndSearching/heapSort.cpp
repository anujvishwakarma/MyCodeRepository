#include <bits/stdc++.h>
using namespace std;

void heapify(std::vector<int> &data, int index, int high){
	int largest = index;
	int leftChild = 2*index+1;
	int rightChild = 2*index+2;
	if(leftChild < high && data[largest]< data[leftChild]){
		largest = leftChild;
	}
	if(rightChild < high && data[largest] < data[rightChild]){
		largest = rightChild;
	}
	if(largest!=index){
		swap(data[index], data[largest]);
		heapify(data, largest, high);
	}
}

void heapSort(std::vector<int> &data, int n){
	int i,j;
	for(i=(n/2)-1; i>=0; i--){
		heapify(data, i, n);
	}
	for(i=n-1;i>=0;i--){
		swap(data[0], data[i]);
		heapify(data, 0, i);
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
	heapSort(input, n);
	for(i=0;i<n;i++){
		cout<<input[i]<<" "; 
	}
	return 0;
}