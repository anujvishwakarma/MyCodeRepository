/*
9 14
7 6 1
8 2 2
6 5 2
0 1 4
2 5 4
8 6 6
2 3 7
0 7 8
1 2 8
3 4 9
5 4 10
1 7 11
3 5 14
7 8 7

*/

#include <bits/stdc++.h>
using namespace std;

void dij(vector<pair<int,int>> graph[1001], int n ,int m, int source){
	int i,j,k;
	std::vector<int> parent(n+1,-1);
	std::vector<int> dist(n+1,INT_MAX);

	priority_queue< pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
	std::vector<pair<int,int>> :: iterator it;

	dist[source] = 0;
	pq.push(make_pair(0, source));

	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		for(it=graph[u].begin();it!=graph[u].end();++it){
			int nextVertex = (*it).first;
			int weight = (*it).second;
			if(dist[nextVertex] > dist[u]+weight){
				dist[nextVertex] = dist[u]+weight;
				pq.push(make_pair(dist[nextVertex], nextVertex));
			}
		}
	}

	for(i=0;i<n;i++){
		cout<<dist[i]<<" ";
	}
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	std::vector<pair<int,int>> graph[1001];
	cin>>n>>m;
	int u,v,w;
	for(i=0;i<m;i++){
		cin>>u>>v>>w;
		graph[u].push_back(make_pair(v,w));
		graph[v].push_back(make_pair(u,w));
	}
	int source;
	cin>>source;
	dij(graph, n , m, source);
	return 0;
}