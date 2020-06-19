#include <bits/stdc++.h>
using namespace std;

int construct(int a[100],int segment[100], int low, int high, int treeindex){
	if(low == high){
		segment[treeindex]=a[low];
		return a[low];
	}
	int mid = (low+high)/2;
	segment[treeindex] = construct(a,segment,low,mid,2*treeindex+1)+construct(a,segment,mid+1,high, 2*treeindex+2);
	return segment[treeindex];
}

int getSum(int segment[100],int s,int e, int qs, int qe, int treeindex){
	if(qs>e || qe<s){
		return 0;
	}
	if(qs<=s && qe>=e){
		return segment[treeindex];
	}
	int mid = (s+e)/2;
	int ans = getSum(segment,s,mid,qs,qe,2*treeindex+1)+getSum(segment,mid+1,e,qs,qe,2*treeindex+2);
	return ans;
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	int a[10000];
	int segment[1000000];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	construct(a,segment,0,n-1,0);
	int query,x,y,ans;
	cin>>query;
	while(query--){
		cin>>x>>y;
		x--;y--;
		ans = getSum(segment,0,n-1,x,y,0);
		cout<<x<<"->"<<y<<" "<<ans<<endl;
	}
	return 0;
}
