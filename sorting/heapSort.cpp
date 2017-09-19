#include <iostream>
using namespace std;

void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}

void heapify(int a[100],int n,int i){
   int left=2*i+1;
   int right=2*i+2;
   int largest=i;
   if(left<n && a[left]>a[largest]){
   	  largest=left;
   }
   if(right<n && a[right]>a[largest]){
   	  largest=right;
   }
   if(largest!=i){
       swap(a[i],a[largest]);
       heapify(a,n,largest);
   }
}

void heapsort(int a[100],int n){
	int i,j,k,l;
	for(i=n/2-1;i>=0;i--){
		heapify(a,n,i);
	}
	for(i=n-1;i>=0;i--){
		swap(a[0],a[i]);
		heapify(a,i,0);
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
	heapsort(a,n);
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}