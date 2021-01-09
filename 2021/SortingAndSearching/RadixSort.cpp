#include <bits/stdc++.h>
using namespace std;

void sortByIndex(std::vector<int> &data, int n, int index){
	int i,j,k,l,m;
	vector<int> tempBuildArray(n,0);
	std::vector<int> freq(10,0);
	for(i=0;i<n;i++){
		freq[(data[i]/index)%10]++;
	}
	for(i=1;i<10;i++){
		freq[i]+=freq[i-1];
	}
	for(i=n-1;i>=0;i--){
		int nextIndex = freq[(((data[i])/index)%10)]-1;
		tempBuildArray[nextIndex] = data[i];
		freq[((data[i]/index)%10)]--;
	}
	for(i=0;i<n;i++){
		data[i]=tempBuildArray[i];
	}
}

int getDigitValue(std::vector<int> &data, int n){
	int max_value = data[0];
	for(int i=0;i<n;i++){
		max_value = max(max_value, data[i]);
	}
	return (max_value);
}	

void radixSort(std::vector<int> &data, int n){
	int index = 1;
	int m = getDigitValue(data, n);
	for(index = 1 ; (m/index)>1 ; index*=10){
		sortByIndex(data, n, index);
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
	radixSort(input, n);
	for(i=0;i<n;i++){
		cout<<input[i]<<" "; 
	}
	return 0;
}