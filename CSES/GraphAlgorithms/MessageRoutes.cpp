#include <bits/stdc++.h>
using namespace std;

map<int, int> parentMap;

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n,x,y;
	std::vector<int> graph[200010];
	cin>>n>>m;
	std::vector<bool> visit(n+1,false);
	std::vector<int> path;
	for(i=0;i<m;i++){
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	queue<pair<int,int>> myQueue;
	bool isFound = false;

	myQueue.push(make_pair(1,0));
	visit[1]=true;
	parentMap[1]=-1;
	int ans = 0;
	while(!myQueue.empty()){
		pair<int,int> data = myQueue.front(); myQueue.pop();
		int vertex = data.first;
		int distance = data.second;
		if(vertex == n){
			isFound = true;
			ans = distance;
			break;
		}
		for(i=0; i < graph[vertex].size(); i++){
			int adj_vertex = graph[vertex][i];
			if(!visit[adj_vertex]){
				visit[adj_vertex] = true;
				parentMap[adj_vertex] = vertex;
				myQueue.push(make_pair(adj_vertex, distance + 1));
			}
		}
	}

	if(!isFound){
		cout<<"IMPOSSIBLE"<<endl;
	}else{
		cout<<ans+1<<endl;
		int curr_parent = n;
		while(curr_parent!=-1){
			path.push_back(curr_parent);
			curr_parent = parentMap[curr_parent];
		}
		reverse(path.begin(), path.end());
		for(i=0;i<path.size();i++){
			cout<<path[i]<<" ";
		}
	}

	return 0;
}