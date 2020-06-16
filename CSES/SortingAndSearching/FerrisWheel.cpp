#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	long long int w,i,j,k,m,n;
	vector<long long int> v;
	cin>>n>>w;
	for(i=0;i<n;i++){
		cin>>k;
		v.push_back(k);
	}
	sort(v.begin(), v.end());
	i=0, j =n-1;
	long long int ans = 0;
	while(i<=j){
		if(v[i]+v[j] > w){
			j--;
		}else {
			i++; j--;
		}
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}
