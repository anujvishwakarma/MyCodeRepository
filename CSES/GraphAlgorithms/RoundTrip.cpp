#include <bits/stdc++.h>
using namespace std;

map<int,int> parent;
bool isFoundCycle = false;
int cycleVertex;

void dfs(vector<int> graph[200010], int vertex, int n,
	vector<bool> &visit){
	visit[vertex] = true;

	for(int i=0;i<graph[vertex].size();i++){
		int next_vertex = graph[vertex][i];
		if(!isFoundCycle){
			if(!visit[next_vertex]){
			parent[next_vertex] = vertex;
			dfs(graph,  next_vertex, n, visit);
			}else{
				if(parent[vertex]!= next_vertex){
					parent[next_vertex] = vertex;
					isFoundCycle = true;
					cycleVertex = vertex;
					//cout<<" cycle at -->" << cycleVertex<<endl;
					break;
				}
			}
		}
	}
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n,x,y;
	cin>>n>>m;
	std::vector<int> graph[200010];
	std::vector<bool> visit(n+1,false);
	for(i=0;i<=n;i++){
		parent[i]=i;
	}
	for(i=0;i<m;i++){
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);	
	}

	for(i=1;i<=n;i++){
		if(!visit[i] && !isFoundCycle){
			dfs(graph, i, n, visit);
		}
	}

	if(isFoundCycle){
		vector<int> cyclePath;
		int parentVertex = parent[cycleVertex];
		cyclePath.push_back(cycleVertex);
		while(parentVertex!=cycleVertex){
			cyclePath.push_back(parentVertex);
			parentVertex = parent[parentVertex];
		}
		cyclePath.push_back(cycleVertex);
		reverse(cyclePath.begin(), cyclePath.end());
		cout<<cyclePath.size()<<endl;
		for(i=0;i<cyclePath.size();i++){
			cout<<cyclePath[i]<<" ";
		}
	}else{
		cout<<"IMPOSSIBLE"<<endl;
	}
	return 0;
}