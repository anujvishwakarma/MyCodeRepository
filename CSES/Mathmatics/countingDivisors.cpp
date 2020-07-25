#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	long long int t,i,j,n,x,ans;
	cin>>t;
	std::vector<long long int> data(1000010,0);
	for(i=1;i<=1000010;i++){
		for(j=i;j<=1000010;j+=i){
			data[j]++;
		}
	}
	while(t--){
		cin>>x;
		cout<<data[x]<<endl;
	}
	return 0;
}