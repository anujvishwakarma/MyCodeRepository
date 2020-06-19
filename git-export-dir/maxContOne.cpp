#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	int a[10000];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	int count=0,ans=0;
	for(i=0;i<n;i++){
		count=0;
		if(a[i]==1){
			while(a[i]==1){
				count++;i++;
			}
		}
		ans=max(ans,count);
	}
	cout<<count<<endl;
	return 0;
}
