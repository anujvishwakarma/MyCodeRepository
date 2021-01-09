#include <bits/stdc++.h>
using namespace std;

void sort(std::vector<int> &input, int n){
	int i,j;
	for(i=0;i<n;i++){
		int min_index = i;
		for(j=i+1;j<n;j++){
			if(input[j] < input[min_index]){
				min_index = j;
			}
		}
		swap(input[i], input[min_index]);
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
	sort(input, n);
	for(i=0;i<n;i++){
		cout<<input[i]<<" "; 
	}
	return 0;
}