#include <bits/stdc++.h>
using namespace std;


/*
TestCase:

9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7

*/


#define INF INT_MAX
int main(int argc, char const *argv[]){
	int i,j,k,m,n,u,v,w;


    vector<pair<int,int> > graph[1000];
    priority_queue< pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >pq;
    cin>>n>>m;

	std::vector<int> key(n,INF);
    std::vector<int> parent(n,-1);
    std::vector<bool> visited(n,false);

    for(i=0;i<m;i++){
    	cin>>u>>v>>w;
    	graph[u].push_back(make_pair(v,w));
    	graph[v].push_back(make_pair(u,w));
    }

    key[0]=0;
    pq.push(make_pair(0,0));

    while(!pq.empty()){
    	u = pq.top().second;
    	pq.pop();
    	visited[u]=true;
    	for(i=0;i<graph[u].size();i++){
    		v=graph[u][i].first;
    		w=graph[u][i].second;
    		if(visited[v]==false && key[v]>w){
    			key[v]=w;
    			pq.push(make_pair(key[v],v));
    			parent[v]=u;
    		}
    	}

    }

    cout<<"MST is==>"<<endl;
    for(i=1;i<n;i++){
    	cout<<i<<" "<<parent[i]<<endl;
    }
	return 0;
}