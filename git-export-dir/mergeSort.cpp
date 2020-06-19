#include <bits/stdc++.h>
using namespace std;

void merge(int a[10],int low, int medium, int high){
	int i,j,k,l;
	int left[100],right[100];
	int n1=(medium-low+1);
    int n2=(high-medium);
	for(i=0;i<n1;i++){
		left[i]=a[low+i];
	}
	for(j=0;j<n2;j++){
		right[j]=a[medium+1+j];
	}
	i=0,j=0;
	k=low;
	while(i<n1 && j<n2){
		if(left[i]<right[j]){
			a[k]=left[i];
			i++;
		}else{
			a[k]=right[j];
			j++;
		}
		k++;
	}
    while(i<n1) {
        a[k]=left[i];i++;k++;
    }
    while(j<n2) {
    	a[k]=right[j];j++;k++;
    }

}

void mergeSort(int a[],int l,int h){
	if(l<h){
		int m=(l+h)/2;
		mergeSort(a,l,m);
		mergeSort(a,m+1,h);
		merge(a,l,m,h);
	}
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	int a[100];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	mergeSort(a,0,n-1);
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
