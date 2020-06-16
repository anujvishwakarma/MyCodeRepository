#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main(int argc, char const *argv[]){
	long long int i,n, ans;
	cin>>n;
	ans=1;
	for(i=1;i<=n;i++){
		ans=((ans %MOD)*2) %MOD;
	}
	cout<<ans<<endl;
	return 0;
}