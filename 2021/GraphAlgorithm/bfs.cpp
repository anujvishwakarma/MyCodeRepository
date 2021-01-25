#include <bits/stdc++.h>
using namespace std;

void input(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void bfs(std::vector<int> graph[1000], std::vector<bool> &visit, int start){
	int i,j,k,l,m;
	visit[start] = true;
	queue<int> myqueue;
	myqueue.push(start);
	while(!myqueue.empty()){
		int curr_vertex = myqueue.front();
		myqueue.pop();
		cout<<curr_vertex<<" ";
		for(i=0;i<graph[curr_vertex].size();i++){
			if(!visit[graph[curr_vertex][i]]){
				visit[graph[curr_vertex][i]] = true;
				myqueue.push(graph[curr_vertex][i]);
			}
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
	bfs(graph, visit, 0);
	return 0;
}