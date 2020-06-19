#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int i,j,k,l,m,n;
	int a[10000],sum;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>sum;
	int w_sum=0;
	int low=0;high=0;
	for(low=0;low<n;low++){
		while(w_sum<sum && high<n){
			w_sum+=a[high];
			high++;
		}
		if(w_sum==sum){
			cout<<low<<" "<<high-1<<endl;
			return;
		}
		w_sum-=a[low];
	}
	return 0;
}