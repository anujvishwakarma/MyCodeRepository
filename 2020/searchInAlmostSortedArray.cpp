#include<bits/stdc++.h>
using namespace std;

int search(std::vector<int> v, int l, int h, int x){
	if(l<=h){
		int m=(l+h)/2;
		cout<<v[m]<<endl;
		if(v[m]==x){
			return m;
		}
		else if(m>l && v[m-1]==x){
			return m-1;
		}
		else if(m<h && v[m+1]==x){
			return m+1;
		}
		if(v[m]>x){
			return search(v,l,m-2,x);
		}
		return search(v,m+2,h,x);

	}
	return -1;
}


int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	std::vector<int> v;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>k;
		v.push_back(k);
	}
	int index = search(v,0,n-1,m);
	cout<<index+1<<endl;
	return 0;
}