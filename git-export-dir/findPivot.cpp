#include <bits/stdc++.h>
using namespace std;

int getValue(int a[10],int n){
	int low=0,high=n-1,mid;
	while(low<=high){
		mid=(low+high)/2;
		if(mid<high && a[mid]==0 && a[mid+1]==1){
			return mid+1;
		}
		if(mid>low && a[mid]==1 && a[mid-1]==0){
			return mid;
		}
		if(a[mid]==1){
			high=mid-1;
		}else{
			low=mid+1;
		}
	}
	return mid;
}

int main(int argc, char const *argv[]){
	int i,j,k,l,n,m;
	int a[1000];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	int count=getValue(a,n);
	cout<<n-count<<endl;
	return 0;
}
