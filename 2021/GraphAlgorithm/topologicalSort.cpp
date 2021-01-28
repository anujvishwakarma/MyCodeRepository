#include <bits/stdc++.h>
using namespace std;

void input(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void topologicalSort(std::vector<int> (&graph)[1000], std::vector<bool> &visit, int start, stack<int> &myStack){
	visit[start] = true;
	for(int i=0;i<graph[start].size();i++){
		int next_vertex = graph[start][i];
		if(!visit[next_vertex]){
			topologicalSort(graph, visit, next_vertex, myStack);
		}
	}
	myStack.push(start);
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	int u,v;
	input();
	std::vector<int> graph[1000];
	stack<int> myStack;
	cin>>n>>m;
	std::vector<bool> visit(n+1, false);
	for(i=0;i<m;i++){
		cin>>u>>v;
		graph[u].push_back(v);
	}
	for(i=0;i<n;i++){
		if(!visit[i]){
			topologicalSort(graph, visit, i, myStack);
		}
	}
	while(!myStack.empty()){
		cout<<myStack.top()<<" ";
		myStack.pop();
	}
	return 0;
}