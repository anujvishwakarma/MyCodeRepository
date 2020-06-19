#include <bits/stdc++.h>
using namespace std;
void swap(int *a,int *b){
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	int a[1000];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	int min_index;
	for(i=0;i<n-1;i++){
        min_index = i;
		for(j=i+1; j<n ;j++){
			if(a[j] < a[min_index]){
				min_index = j;
			}
		}
		swap(&a[i], &a[min_index]);
	}
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
