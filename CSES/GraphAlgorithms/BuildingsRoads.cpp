#include <bits/stdc++.h>
using namespace std;


void dfs(vector<int> graph[1005], int curr_node, vector<bool> &visit){
	int i;
	visit[curr_node]=true;
	for(i=0;i<graph[curr_node].size();i++){
		int nextNode = graph[curr_node][i];
		if(!visit[nextNode]){
			dfs(graph, nextNode, visit);
		}
	}
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n,x,y;
	std::vector<int> graph[100009];
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	int ans = 0;
	vector<bool> visit(n+1, false);
	vector<int> path;
	for(i=1;i<=n;i++){
		if(!visit[i]){
			ans++;
			dfs(graph, i, visit);
			path.push_back(i);
		}
	}
	cout<<ans-1<<endl;
	if(ans>1){
		for(i=1;i<path.size();i++){
			cout<<path[i-1]<<" "<<path[i]<<endl;
		}
	}
	return 0;
}