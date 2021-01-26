#include <bits/stdc++.h>
using namespace std;

void input(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}


int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	int u,v;
	input();
	cin>>n>>m;
	std::vector<pair<int,int>> edges(n+1);
	for(i=0;i<m;i++){
		cin>>u>>v;
		edges.push_back(make_pair(u,v));
	}
	bool isCyc = isCycle();
	cout<<isCyc<<endl;
	return 0;
}