#include <bits/stdc++.h>
using namespace std;

int getCeilIndex(std::vector<int> tempData, int low, int high, int key){
	while(high - low > 1){
		int m = (high+low)/2;
		if(tempData[m]>=key){
			high = m;
		}else{
			low = m;
		}
	}
	return high;
}

int getLisCeil(std::vector<int> data, int n){
	int i,j,k,l,m;
	std::vector<int> tempdata(n,0);
	tempdata[0] = (data[0]);
	int maxLength = 1;
	for(i=1;i<n;i++){
		if(data[i]<tempdata[0]){
			tempdata[0]=data[i];
		}
		else if(data[i]>tempdata[maxLength - 1]){
			tempdata[maxLength] = data[i];
			//this is the only condition that increase the overall lenght of key.
			maxLength++;
		}
		else {
			int ceilIndex = getCeilIndex(tempdata, -1, maxLength - 1, data[i]);
			tempdata[ceilIndex] = data[i];
		}
	}
	return maxLength;
}

int getLisByDP(std::vector<int> data, int n){
	int i,j,k,l,m;
	std::vector<int> dp(n,1);
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			if(data[i]>data[j] && dp[i]<1+dp[j]){
				dp[i]=1+dp[j];
			}
		}
	}
	return dp[n-1];
}

int main(int argc, char const *argv[]){
	int i,j,k,m,n,l;
	cin>>n;
	std::vector<int> data;
	for(i=0;i<n;i++){
		cin>>k;
		data.push_back(k);
	}
	int getLis = getLisByDP(data, n);

	int getLisByCeil = getLisCeil(data,n);

	cout<<getLis<<" "<<getLisByCeil<<endl;
	return 0;
}