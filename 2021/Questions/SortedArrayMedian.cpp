#include <bits/stdc++.h>
using namespace std;

int getMed(std::vector<int> data, int n){
	if(n%2==0){
		return (data[n/2] + data[n/2-1])/2;
	}
	return data[n/2];
}

int getMedian(std::vector<int> data1, std::vector<int> data2, int n){
	if(n<=0){
		return -1;
	}
	if(n==1){
		return (data1[0]+data2[0])/2;
	}
	if(n==2){
		int max_data = max(data1[0], data2[0]);
		int min_data = max(data1[1], data2[1]);
		return (max_data + min_data)/2;
	}
	int med_1 = getMed(data1, n);
	int med_2 = getMed(data2, n);

	if(med_2 == med_1){
		return med_1;
	}
	if(med_2>med_1){
		if(n%2 ==0 ){
			vector<int> temp_v(data1.begin()+ n/2 - 1), data1.end());
			return getMedian(temp_v, 
				std::vector<int> v(data2.begin(), data2.begin()+n/2, n -n/2 +1);
		}
		return getMedian(std::vector<int> v(data1.begin()+n/2), 
				std::vector<int> v(data2.begin(), data2.begin()+n/2, n -n/2);
	}
	if(n%2 ==0 ){
			return getMedian(std::vector<int> v(data2.begin()+n/2 - 1), 
				std::vector<int> v(data1.begin(), data1.begin()+n/2, n -n/2 +1);
	}
	return getMedian(std::vector<int> v(data2.begin()+n/2 - 1), 
		std::vector<int> v(data1.begin(), data1.begin()+n/2, n -n/2 +1);
}

int main(int argc, char const *argv[]){
	int i,j,k,l,n;
	std::vector<int> data1;
	std::vector<int> data2;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>k;
		data1.push_back(k);
	}
	for(i=0;i<n;i++){
		cin>>k;
		data2.push_back(k);
	}
	int mediun = getMedian(data1, data2, n);

	return 0;
}