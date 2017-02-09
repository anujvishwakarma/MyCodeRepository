
#include <bits/stdc++.h>
using namespace std;
int dist[100];
typedef pair<int,int> ipair;
int main(int argc, char const *argv[])
{
	int i,j,k,l,m,n,u,v,w;
	int v1,v2;
	vector<ipair>g[1000];
    int f[1000]={0};
	cin>>m>>n;
	for(i=0;i<n;i++){
		cin>>u>>v>>w;
		u--;
		v--;
		g[u].push_back(make_pair(v,w));
		g[v].push_back(make_pair(u,w));
		dist[u]=9999999;
		dist[v]=9999999;
	}

    priority_queue< ipair,vector<ipair>,greater<ipair> >pq;
    int src;
    cin>>src;
    src--;
    pq.push(make_pair(src,0));
    dist[src]=0;
    while(!pq.empty()){
    	m=pq.top().first;
    	k=pq.top().second;
        pq.pop();
    	for(i=0;i<g[m].size();i++){
             v1=g[m][i].first;
             v2=g[m][i].second;
             if(!f[m] && dist[v1]>k+v2){
             	dist[v1]=k+v2;
             	pq.push(make_pair(v1,dist[v1]));
             }
    	}
        f[m]=1;
    }
    
    for(i=0;i<n;i++){
    	cout<<dist[i]<<" ";
    }


	return 0;
}