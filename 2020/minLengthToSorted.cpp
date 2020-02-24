#include <bits/stdc++.h>
using namespace std;

void getLength(std::vector<int> v, int n){
	int i=0,j,k,l,m;
	int s=0,e=n-1;
	while(i<n-1 && v[i]<v[i+1]){
		s++;
		i++;
	}
	if(s==n-1){
		cout<<"Already sorted";
		return;
	}
	i=n-2;
	while(i>=0 && v[i]<v[i+1]){
		e--;
		i--;
	}
	int min_v=v[s], max_v=v[s];
	for(i=s+1;i<=e;i++){
		min_v=min(min_v, v[i]);
		max_v=max(max_v,v[i]);
	}
	for(i=0;i<s;i++){
		if(v[i]>min_v){
			s=i;
			break;
		}
	}
	for(i=n-1;i>=e;i--){
		if(max_v>v[i]){
			e=i;
			break;
		}
	}
	cout<<s+1<<" and "<<e+1<<endl;
}

int main(int argc, char const *argv[]){
	int i,j,k,m,n;
	std::vector<int> v;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>k;
		v.push_back(k);
	}
	getLength(v,n);
	return 0;
}