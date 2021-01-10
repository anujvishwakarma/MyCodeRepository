#include <bits/stdc++.h>
using namespace std;

/*
9 14
7 6 1
8 2 1
6 5 2
0 1 4
2 5 4
8 6 6
2 3 7
0 7 8
1 2 8
3 4 9
5 4 10
1 7 11
3 5 14
7 8 7


*/
int find(int u, std::vector<int> &parent, std::vector<int> &path){
	while(u!= parent[u]){
		parent[u] = parent[parent[u]];
		u = parent[u];
	}
	return u;
}

void merge(int u, int v, std::vector<int> &parent, std::vector<int> &path){
	if(path[u]<path[v]){
		path[v]+=path[u];
		parent[u]=v;
	}else{
		path[u]+=path[v];
		parent[v]=u;
	}
}

void kruskal(std::vector<pair<int, pair<int,int>>> graph, int vertices, int edges, std::vector<int> &parent, std::vector<int> &path){
	int i,j,k,l,m;
	int u,v,w;
	int cost = 0;
	for(i=0;i<edges;i++){
		 w = graph[i].first;
		 u = graph[i].second.first;
		 v = graph[i].second.second;
		u = find(u, parent, path);
		v = find(v, parent, path);
		if(u!=v){
			cost+=w;
			cout<<"Vertex inclued --> "<< graph[i].second.first <<" "<<graph[i].second.second<<endl;
			merge(u,v, parent, path);
		}
	}
	cout<<"Total cost of MST "<<cost<<endl;
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	vector<pair<int, pair<int,int> >> graph;
	cin>>n>>m;
	int u,v,w;
	for(i=0;i<m;i++){
		cin>>u>>v>>w;
		graph.push_back(make_pair(w, make_pair(u,v)));
	}

	std::vector<int> parent(n);
	std::vector<int> path(n);
	sort(graph.begin(), graph.end());
	for(i=0;i<=n;i++){
		parent[i]=i;
		path[i]=1;
	}
	kruskal(graph, n, m, parent, path);
	return 0;
}