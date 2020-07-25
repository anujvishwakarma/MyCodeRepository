#include <bits/stdc++.h>
using namespace std;

long long int pow(long long int x, long long int y){
	long long int ans = 1;
	long long int mod = 1e9+7;
	while(y){
		if(y & 1){
			ans = (ans*x) % mod;
		}
	  y=y>>1;
	  x=(x*x) % mod;	
	}
	return ans;
}

int main(int argc, char const *argv[]){
	long long int a,b,t;
	cin>>t;
	while(t--){
		cin>>a>>b;
		long long int ans = pow(a,b);
		cout<<ans<<endl;
	}
	return 0;
}