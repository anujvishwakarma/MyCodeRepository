#include <bits/stdc++.h>
using namespace std;

int getSteps(std::vector<int> data, int n){
	int i,j,k,l,m;
	std::vector<int> dp(n+1);
	int maxReach = data[0];
	int step = data[0];
	int jump = 1;

	for(i=1;i<n;i++){
		if(i==n-1){
			return jump;
		}
		maxReach = max(maxReach, i + data[i]);
		step--;
		if(step==0){
			jump++;
			if(i>=maxReach){
				return -1;
			}
			step = maxReach - 1;
		}
	}
	return -1;
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	std::vector<int> data;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>k;
		data.push_back(k);
	}
	int minSteps = getSteps(data, n);
	return 0;
}