#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> graph[10000], int visit[1000], int v){
	int i,j,k,l,m,n;
	queue<int> q;
	q.push(0);
	visit[0]=1;
	while(!q.empty()) {
	    int v = q.front();
	    cout<<v<<endl;
	    q.pop();
	    for(i=0;i<graph[v].size();i++){
	    	if(!visit[graph[v][i]]){
	    		visit[graph[v][i]]=1;
	    		q.push(graph[v][i]);
	    	}
	    }
	}
}

int main(int argc, char const *argv[]){
	int i,j,k,m,l,n;
	std::vector<int> graph[10000];
	int visit[1000];
	int u,v;
	cin>>n>>m;
	for(i=0;i<n;i++){
		visit[i]=0;
	}
	for(i=0;i<m;i++){
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	bfs(graph, visit, 0);
	return 0;
}


