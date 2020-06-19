#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	int row[100]={0},col[100]={0};
	int a[100][100];
	cin>>n>>m;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin>>a[i][j];
			if(a[i][j]==0){
				row[i]=1;
				col[j]=1;
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(row[i] || col[j]){
				a[i][j]=0;
			}
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}