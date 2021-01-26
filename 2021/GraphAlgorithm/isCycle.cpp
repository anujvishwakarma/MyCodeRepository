#include <bits/stdc++.h>
using namespace std;

void input(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

bool isCycle(std::vector<int> (&graph)[1000], std::vector<bool> &visit, std::vector<bool> &recurse, int start){
	if(!visit[start]){
		visit[start] = true;
		recurse[start] = true;

		for(int i=0;i<graph[start].size();i++){
			int next_vertex = graph[start][i];
			if(!visit[next_vertex] && isCycle(graph, visit, recurse, next_vertex)){
				return true;
			}
			else if(recurse[next_vertex]){
				return true;
			}
		}
	}
	recurse[start] = false;
	return false;
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	int u,v;
	input();
	std::vector<int> graph[1000];
	cin>>n>>m;
	std::vector<bool> visit(n+1, false);
	std::vector<bool> recurse(n+1, false);
	for(i=0;i<m;i++){
		cin>>u>>v;
		graph[u].push_back(v);
	//	graph[v].push_back(u);
	}
	bool isC = isCycle(graph, visit, recurse, 0);
	cout<<isC<<endl;
	return 0;
}