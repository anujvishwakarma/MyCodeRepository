#include <bits/stdc++.h>
using namespace std;

typedef pair<long long int ,long long int > pii;

void dijkstras(vector<pair<long long int ,long long int > > graph[200010], long long int  startVertex, 
	vector<bool> &visit, vector<long long int > &distance){
	
	priority_queue< pii , vector<pii>, greater<pii>> pq; 
	distance[startVertex] = 0;

	pq.push({0, startVertex});

	while(!pq.empty()){
		pair<long long int ,long long int > curr_data = pq.top(); pq.pop();
		long long int  curr_vertex = curr_data.second;
		long long int  curr_distance = curr_data.first;
		if(visit[curr_vertex]){
			continue;
		}
		visit[curr_vertex] = true;
		for(long long int  i=0; i< graph[curr_vertex].size(); i++){
			long long int  nextVertex = graph[curr_vertex][i].first;
			if(distance[nextVertex] > curr_distance + 
				graph[curr_vertex][i].second){
				distance[nextVertex] = curr_distance + graph[curr_vertex][i].second;
				pq.push(make_pair(distance[nextVertex],nextVertex));
			}

		}
	}
}

int  main(int  argc, char const *argv[]){
	long long int  i,j,k,l,m,n,u,v,w;
	std::vector<pair<long long int ,long long int >> graph[200010];
	cin>>n>>m;
	vector<bool> visit(n+1,false);
	vector<long long int > distance(n+1, 1000000000LL * m + 1LL);
	for(i=0;i<m;i++){
		cin>>u>>v>>w;
		graph[u].push_back(make_pair(v,w));
		//graph[v].push_back(make_pair(u,w));
	}

	dijkstras(graph, 1, visit, distance);

	for(i=1;i<=n;i++){
		cout<<distance[i]<<" ";
	}
	return 0;
}