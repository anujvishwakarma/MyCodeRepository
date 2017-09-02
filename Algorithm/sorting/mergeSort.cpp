#include <iostream>
using namespace std;


void merge(int a[10],int l,int m,int h){
	int n1=m-l+1;
	int n2=h-m;
	int i,j,k;
	int left[10001];
	int right[10001];
    for(i=0;i<n1;i++){
    	left[i]=a[l+i];
    }
    for(i=0;i<n2;i++){
    	right[i]=a[m+1+i];
    }
    i=0;j=0;k=l;
    while(i<n1 && j<n2){
    	if(left[i]<=right[i]){
    		a[k]=left[i];
    		i++;
    	}
    	else{
    		a[k]=right[j];
    		j++;
    	}
    	k++;
    }
    while(i<n1){
    	a[k]=left[i];
    	i++;k++;
    }
    while(j<n2){
    	a[k]=right[j];
    	j++;k++;
    }
}



void mergesort(int a[10],int l,int h){
	if(l<h){
      int m=(l+h)/2;
      mergesort(a,l,m);
      mergesort(a,m+1,h);
      merge(a,l,m,h);
	}
}
int main(int argc, char const *argv[])
{
	int i,j,k,l,m,n;
	int a[10001];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	mergesort(a,0,n-1);
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}