#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	long long int i,j,k,l,m,n,ans=0;
	vector<long long int> v;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>k;
		v.push_back(k);
	}
	for(i=1;i<n;i++){
		if(v[i]<v[i-1]){
			k=abs(v[i-1]-v[i]);
			v[i]+=k;
			ans+=k;
		}
	}
	cout<<ans<<endl;
	return 0;
}