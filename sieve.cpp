#include <bits/stdc++.h>
using namespace std;
int prime[1000];
void processArray(int curr_prime, int n){
	for(int i=curr_prime*curr_prime ;i<n;i+=curr_prime){
		prime[i]=0;
	}
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n,o,p;
	prime[1]=0;
	cin>>n;
	for(i=2;i<n;i++){
		prime[i]=1;
	}
	for(i=2;i<n;i++){
		if(prime[i]){
			processArray(i,n);
		}
	}
	for(i=2;i<n;i++){
		if(prime[i]){
			cout<<i<<endl;
		}
	}
	return 0;
}
