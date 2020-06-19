#include <bits/stdc++.h>
using namespace std;


void dfs(vector<int> graph[10000], int visit[1000],int v){
	visit[v]=1;
	cout<<v<<endl;
	for(int i=0;i<graph[v].size();i++){
		if(!visit[graph[v][i]]){
			dfs(graph, visit, graph[v][i]);
		}
	}
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	int a[1000];
	std::vector<int> graph[1000];
	int visit[1000];
	cin>>n>>m;
	int u,v;
	for(i=0;i<n;i++){
		visit[i]=0;
	}
	for(i=0;i<m;i++){
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(graph,visit,0);
	return 0;
}