#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
    vector<int> v;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>k;
		v.push_back(k);
	}
	m++;
	priority_queue<int,vector<int>,greater<int> >pq;
	for(i=0;i<m;i++){
		pq.push(v[i]);
	}
	int value;
	for(i=m;i<n;i++){
		value=pq.top();
		cout<<value<<" ";
		pq.pop();
		pq.push(v[i]);
	}
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}

	return 0;
}