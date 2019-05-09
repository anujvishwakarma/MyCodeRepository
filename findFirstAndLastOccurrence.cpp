//Questions: https://www.techiedelight.com/find-first-or-last-occurrence-of-a-given-number-sorted-array/

#include <bits/stdc++.h>
using namespace std;


int firstOccuerence(int a[10000],int n,int k){
	int mid,low=0,high=n-1;
	while(low<=high) {
	    mid=(low+high)/2;
	    if((mid==low && a[mid]==k)||(low<mid && a[mid]==k && a[mid-1]!=k)){
	    	return mid;
	    }
	    if(a[mid]<k){
	    	low=mid+1;
	    }else{
	    	high=mid-1;
	    }
	}
	return -1;
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	int a[1000];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>k;
	int left = firstOccuerence(a,n,k);
	cout<<left+1<<endl;
	return 0;
}