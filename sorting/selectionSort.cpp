#include <iostream>
using namespace std;
void swap(int *a,int *b){
   int t=*a;
   *a=*b;
   *b=t;
}
int main(int argc, char const *argv[])
{
	int i,j,k,l,m,n,min;
	int a[10001];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<n;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(a[j]<a[min]){
				min=j;
			}
		}
		swap(a[i],a[min]);
	}
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}