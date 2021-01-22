#include <bits/stdc++.h>
using namespace std;

void input(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void printAllPrime(int n){
	int i,j,k;
	std::vector<bool> isPrime(n+1, true);
	isPrime[1]=false;
	for(i=2;i*i<=n;i++){
		if(isPrime[i]){
			for(k=i*i;k<=n;k+=i){
				isPrime[k]=false;
			}
		}
	}
	for(i=2;i<=n;i++){
		if(isPrime[i]){
			cout<<i<<" ";
		}
	}
}

int main(int argc, char const *argv[]){
	input();
	int i,j,k,l,m,n;
	cin>>n;
	printAllPrime(n);
	return 0;
}