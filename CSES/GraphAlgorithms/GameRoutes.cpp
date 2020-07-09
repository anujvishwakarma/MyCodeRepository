#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

void dfs(vector<int> graph[100009], int vertex,int n,  vector<int> &visit,
 vector<int> &ways){
	visit[vertex]=1;
	if(vertex == n){
		ways[vertex] = 1;
		visit[vertex] = 2;
		return;
	}
	for(int i=0;i< graph[vertex].size();i++){
		int next_vertex = graph[vertex][i];
		if(visit[next_vertex]== -1){
			dfs(graph, next_vertex, n, visit, ways);
		}
		ways[vertex]+=ways[next_vertex] % mod;
		ways[vertex]%=mod;
	}
	visit[vertex] = 2;
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n,u,v;
	cin>>n>>m;
	std::vector<int> graph[100009];
	for(i=0;i<m;i++){
		cin>>u>>v;
		graph[u].push_back(v);
	}
	std::vector<int> visit(n+1, -1);
	std::vector<int> ways(n+1,0);
	dfs(graph, 1,n, visit, ways);
	cout<<ways[1]<<endl;
	return 0;
}