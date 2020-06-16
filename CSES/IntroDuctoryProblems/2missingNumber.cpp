#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	long long int i,n,k;
	cin>>n;
	long long int sum = 0;
	for(i=0;i<n-1;i++){
		cin>>k;
		sum+=k;
	}
	long long int ans =  n*(n+1)/2;
	cout<<ans-sum<<endl;
	return 0;
}