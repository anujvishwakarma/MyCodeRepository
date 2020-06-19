#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
	int i,j,k,m,n;
	int a[1000];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	cin>>k;
    int l =0, r=n-1;
    while(l<=r){
    	m = (l+r)/2;
    	if(a[m]==k){
    		cout<<"Found at "<<m<<endl;
    		return 0;
    	}
    	else if(a[m] > k){
    		r=m-1;
    	}else{
    		l=m+1;
    	}
    }
    cout<<"Not Found"<<endl;
	return 0;
}