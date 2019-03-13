#include <bits/stdc++.h>
using namespace std;

void swap(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}
int main(int argc, char const *argv[])
{
	int i,j,k,l,m,n;
	int a[10001];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i]>a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}