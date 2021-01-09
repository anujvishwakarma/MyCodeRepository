#include <bits/stdc++.h>
using namespace std;

void bubbleSort(std::vector<int> &input, int size){
	int i,j;
	for(i=0;i<size;i++){
		for(j=0;j<size-1;j++){
			if(input[j]>input[j+1]){
				swap(input[j], input[j+1]);
			}
		}
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
	bubbleSort(input, n);
	for(i=0;i<n;i++){
		cout<<input[i]<<" ";
	}
	return 0;
}