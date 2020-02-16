#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
	std::vector<int> v;
	int i,j,k,m,n;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>k;
		v.push_back(k);
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(v[i]>v[j]){
				swap(v[i],v[j]);
			}
		}
	}
	for(i=0;i<n;i++){
		cout<<v[i]<<" ";
	}
	return 0;
}