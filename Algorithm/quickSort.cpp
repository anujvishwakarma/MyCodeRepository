#include <iostream>
using namespace std;

void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}
int part(int a[100],int l,int h){
	int pivot=a[h];
	int j=l-1,i;
	for(i=l;i<=h-1;i++){
		if(a[i]<=pivot){
			j++;
			swap(&a[j],&a[i]);
		}
	}
	swap(&a[j+1],&a[h]);
	return j+1;
}



void quicksort(int a[100],int l,int h){
	if(l<h){
		int p=part(a,l,h);
		quicksort(a,l,p-1);
		quicksort(a,p+1,h);
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
	quicksort(a,0,n-1);
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}