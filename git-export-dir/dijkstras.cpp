#include <bits/stdc++.h>
using namespace  std;
typedef pair<int,int> pii;
int dist[10000];
int visit[10000];
void dij(vector<pii> graph[1000],int n){
     int src;
     priority_queue<pii,vector<pii>,greater<pii> > pq;
     cin>>src; dist[src]=0;
     visit[src]=1;
     pq.push(make_pair(0,src));
     while(!pq.empty()){
     	int d=pq.top().first;
     	int u=pq.top().second;
     	pq.pop();
     	for(int i=0;i<graph[u].size();i++){
     		int v=graph[u][i].first;
     		if(!visit[v] && dist[v]>d+graph[u][i].second){
     			dist[v]=d+graph[u][i].second;
     			pq.push(make_pair(dist[v],v));
     		}
     	}
     	visit[u]=1;
     }
     for(int i=1;i<=n;i++){
     	cout<<dist[i]<<" ";
     }
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	std::vector<pii> graph[1000];
	int u,v,w;
	cin>>m>>n;
	for(i=0;i<m;i++){
		cin>>u>>v>>w;
		graph[u].push_back(make_pair(v,w));
		graph[v].push_back(make_pair(u,w));
		dist[u]=999999;
		dist[v]=999999;
	}
	dij(graph,n);
	return 0;
}
