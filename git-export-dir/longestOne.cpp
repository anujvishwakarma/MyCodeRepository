#include <bits/stdc++.h>
using namespace std;
int main(){
	int i,j,k,m,n;
	int a[10000];
	int index=-1;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	int prev_zero=-1;
	int prev_prev_zero=-1;
	int maxLength=0;
	for(i=0;i<n;i++){
		if(a[i]==0){
			if(i - prev_prev_zero > maxLength){
				maxLength = i-prev_prev_zero;
				index=i;
			}
			prev_prev_zero=prev_zero;
			prev_zero=i;
		}
	}
	cout<<(index==-1?n:index)<<endl;
}
