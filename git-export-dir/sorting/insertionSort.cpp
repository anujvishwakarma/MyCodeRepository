#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int i,j,k,l,m,n;
	int a[100000];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=1;i<n;i++){
        k=a[i];
        j=i-1;
        while(j>=0 && a[j]>k){
        	a[j+1]=a[j];
        	j--;
        }
      a[j+1]=k;
	}


	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}