#include <bits/stdc++.h>
using namespace std;

bool jumpSearch(std::vector<int> v, int n, int data){
	int blockend = sqrt(n);
	int blockstart = 0;
	while(v[min(blockend,n)-1] <data){
		blockstart = blockend;
		blockend += sqrt(n);
		if(blockstart >= n){
			return false;
		}
	}

	while(v[blockstart] < data){
		blockstart++;
		if(blockstart == min((int)sqrt(n),n) ){
			return false;
		}
	}

	if(v[blockstart] == data){
		return true;
	}
	return false;
}


int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	cin>>n>>m;
	std::vector<int> v;
	for(i=0;i<n;i++){
		cin>>k;
		v.push_back(k);
	}
	cout<<jumpSearch(v, n, k)<<endl;
	return 0;
}