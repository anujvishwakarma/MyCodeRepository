#include <bits/stdc++.h>
using namespace std;

bool jumpSearch(int a[10],int n, int jumpValue, int k){
   int prev = 0, step = 0;
   while(step < n && a[step] < k){
   	  prev=step;
   	  step+=jumpValue;
   }
   while(a[prev] < k ){
   	  prev++;
   	  if(prev >= n){
   	  	return false;
   	  }else if(a[prev] == k){
   	  	return true;
   	  }
   }
   return false;
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	int a[1000];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>k;
	bool isFound=jumpSearch(a,n,sqrt(n), k);
	cout<< (isFound ? "Yes" : "No")<<endl;

	return 0;
}