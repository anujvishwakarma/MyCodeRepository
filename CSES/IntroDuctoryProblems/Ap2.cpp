#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	long long int i,j,k,l,m,n,sum=0, curr_sum =0 ,ans=INT_MAX;
	std::vector<long long int> v;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>k;
		sum+=k;
		v.push_back(k);
	}
	for(i=0;i< (1<<n);i++){
		curr_sum=0;
		for(j=0;j<n;j++){
			if(i & 1<<j){
				curr_sum+=v[j];
			}
		}
		ans=min(ans, abs((sum-curr_sum)- curr_sum));
	}
	cout<<ans<<endl;
	return 0;
}