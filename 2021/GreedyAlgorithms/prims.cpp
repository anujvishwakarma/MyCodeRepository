#include <bits/stdc++.h>
using namespace std;


void prims(vector<pair<int,int>> graph[1001], int n ,int m){
	int i,j,k;
	std::vector<int> parent(n,-1);
	std::vector<int> key(n,INT_MAX);
	std::vector<bool> inMST(n,false);

	priority_queue< pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
	std::vector<pair<int,int>> :: iterator it;

	key[0]=0;
	//[weight/Vertex]
	pq.push(make_pair(0,0));
	int cost =0;
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		inMST[u]=true;
		cout<<"u is "<<u<<endl;
		cost+=key[u];
		for(it=graph[u].begin(); it!=graph[u].end(); ++it){
			int nextVertex = (*it).first;
			int weight = (*it).second;
			if(!inMST[nextVertex] && key[nextVertex]>weight){
				parent[nextVertex] = u;
				key[nextVertex] = weight;
				pq.push(make_pair(weight, nextVertex));
			}
		}
	}
	cout<<cost<<endl;
	for(i=1;i<n;i++){
		cout<<i<<" --> "<< parent[i]<<endl;
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
	prims(graph, n , m);
	return 0;
}