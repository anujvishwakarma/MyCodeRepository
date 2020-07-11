#include <bits/stdc++.h>
using namespace std;

void dfs(int vertex,int n, vector<int> graph[200008],
 vector<bool> &visit, vector<int> &distance){
	visit[vertex] = true;
	distance[vertex]++;
	for(int i=0;i<graph[vertex].size();i++){
		if(!visit[graph[vertex][i]]){
			dfs(graph[vertex][i],n, graph, visit, distance);
		}
		distance[vertex]+=distance[graph[vertex][i]];
	}
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n,x,y;
	cin>>n;
	std::vector<int> graph[200008];
	std::vector<bool> visit(n+1, false);
	std::vector<int> distance(n+1,0);
	for(i=2;i<=n;i++){
		cin>>x;
		graph[x].push_back(i);
	}

	for(i=1;i<=n;i++){
		if(!visit[i]){
			dfs(i,n,graph,visit, distance);
		}
	}
	for(i=1;i<=n;i++){
		cout<<distance[i]-1<<" ";
	}
	return 0;
}