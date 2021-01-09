#include <bits/stdc++.h>
using namespace std;

void insertionSort(std::vector<int> &data, int n){
	int i,j,key;
	for(i=1;i<n;i++){
		j = i-1; key = data[i];
		while(j>=0 && key<data[j]){
			data[j+1] = data[j];
			j--;
		}
		data[j+1]=key;
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
	insertionSort(input, n);
	for(i=0;i<n;i++){
		cout<<input[i]<<" "; 
	}
	return 0;
}