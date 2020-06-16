#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	long long int i,j,k,l,m,n, sum =0;
	cin>>n;
	std::vector<long long int> data;
	for(i=0;i<n;i++){
		cin>>k;
		sum+=k;
		data.push_back(k);
	}
	long long int ans=0;
	sort(data.begin(), data.end());
	long long int med = data[n/2];
	for(i=0;i<n;i++){
		ans+=abs(data[i]-med);
	}
	cout<<ans<<endl;
	return 0;
}