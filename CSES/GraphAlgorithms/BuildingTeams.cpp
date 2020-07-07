#include <bits/stdc++.h>
using namespace std;

map<int,int> color;
bool findMore = true;

void bfs(vector<int> graph[200010],vector<bool> &visit ,
	int vertex, int nodes){
	queue<pair<int,int>> myQueue;
	visit[vertex]=true;
	myQueue.push(make_pair(vertex, 1));
	color[vertex]=1;

	while(!myQueue.empty()){
		pair<int,int> data = myQueue.front(); myQueue.pop();
		int curr_vertex = data.first;
		int curr_color = data.second;

		for(int i=0; i<graph[curr_vertex].size(); i++){
			int adj_vertex = graph[curr_vertex][i];
			if(!visit[adj_vertex]){
				visit[adj_vertex] = true;
				color[adj_vertex] = 1 - curr_color;
				myQueue.push(make_pair(adj_vertex, 1-curr_color));
			}else{
				if(color[adj_vertex] == curr_color){
					findMore = false;
					break;
				}
			}
		}
	}
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n,x,y;
	cin>>n>>m;
	vector<int> graph[200010];
	for(i=0;i<m;i++){
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	std::vector<bool> visit(n+1,false);
	for(i=1;i<=n;i++){
		if(!visit[i] && findMore){
			bfs(graph,visit, i, n);
		}
	}
	if(!findMore){
		cout<<"IMPOSSIBLE"<<endl;
	}else{
		for(auto it=color.begin(); it!=color.end(); ++it){
			if(it->second == 0){
				cout<<"2"<<" ";
			}else{
				cout<<"1"<<" ";
			}
		}
	}
	return 0;
}