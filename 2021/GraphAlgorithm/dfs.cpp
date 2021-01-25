#include <bits/stdc++.h>
using namespace std;

void input(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void dfs(vector<int> (&graph)[1000], std::vector<bool> &visit, int start){
	int i,j,k;
	visit[start]=true;
	cout<<start<<" ";
	for(i=0;i<graph[start].size();i++){
		int next_vertex = graph[start][i];
		if(!visit[next_vertex]){
			dfs(graph, visit, next_vertex);
		}
	}
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	int u,v;
	input();
	std::vector<int> graph[1000];
	cin>>n>>m;
	std::vector<bool> visit(n+1, false);
	for(i=0;i<m;i++){
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(graph, visit, 1);
	return 0;
}