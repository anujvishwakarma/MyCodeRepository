#include <bits/stdc++.h>
using namespace std;

void input(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

int find(int x, vector<int> &parent){
	while(x!=parent[x]){
		x=parent[x];
	}
	return x;
}

int merge(int x, int y, std::vector<int> &parent){
	parent[y]=x;
}

bool isCycle(vector<pair<int,int>> &edges, int n, std::vector<int> &parent){
	int i;
	for(i=0;i<edges.size();i++){
		int u = find(edges[i].first, parent);
		int v = find(edges[i].second, parent);
		if(u!=v){
			merge(u,v, parent);
		}else{
			return true;
		}
	}
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
	std::vector<int> parent;
	for(i=0;i<n;i++){
		parent.push_back(i);
	}
	bool isCyc = isCycle(edges, n, parent);
	cout<<isCyc<<endl;
	return 0;
}