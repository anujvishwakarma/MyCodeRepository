#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
	int i,j,k,n,l,m;
	int a[100][100];
	cin>>n;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<i;j++){
			k = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = k;
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}