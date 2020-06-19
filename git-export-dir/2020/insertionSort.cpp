#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	std::vector<int> v;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>k;
		v.push_back(k);
	}
	for(i=1;i<n;i++){
		k=v[i];
		j=i-1;
		while(j>=0 && v[j]>k){
			v[j+1]=v[j];
			j--;
		}
		v[j+1]=k;
	}
	for(i=0;i<n;i++){
		cout<<v[i]<<" ";
	}
	return 0;
}