#include <bits/stdc++.h>
using namespace std;

long int farthestVertex = 1;
long long int maxDistance = -1;
long long int diameter = 0;
vector<long long int> graph[200008];

void dfs(int vertex, std::vector<bool> &visit ,long long int curr_distance){
	visit[vertex] = true;
	if(curr_distance > maxDistance){
		farthestVertex = vertex;
		maxDistance = curr_distance;
		diameter = curr_distance;
	}
	for(int i=0;i<graph[vertex].size();i++){
		int next_vertex = graph[vertex][i];
		if(!visit[next_vertex]){
			dfs(next_vertex, visit, curr_distance+1);
		}
	}
}

int main(int argc, char const *argv[]){
	long long int i,j,k,l,m,n,u,v;
	cin>>n;
	for(i=0;i<n-1;i++){
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	std::vector<bool> visit(n+1,0);
	dfs(1, visit, 0);
	//cout<<"farthestVertex --> "<<farthestVertex<<endl;
	fill(visit.begin(), visit.end(), false);

	dfs(farthestVertex, visit, 0);	
	cout<<diameter<<endl;
	return 0;
}