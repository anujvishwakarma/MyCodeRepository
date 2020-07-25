#include <bits/stdc++.h>
using namespace std;

long long int pow(long long int x, long long int y, long long int mod){
	long long int ans = 1;
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
	long long int a,b,c,ans,t;
	long long int mod = 1e9+7;
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		ans = pow(b,c, mod-1);
		ans = pow(a,ans, mod);
		cout<<ans<<endl;
	}
	return 0;
}