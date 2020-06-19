#include <bits/stdc++.h>
using namespace std;

int find(int u,int parent[100]){
   if(u!=parent[u]){
   	 parent[u]=parent[parent[u]];                         //path compression
   	 u=parent[u];
   } 
   return u;
}

void unite(int u,int v,int rank[10],int parent[100]){     //union by rank
   if(rank[u]<rank[v]){
   	  parent[u]=v;
      rank[v]+=rank[u];
   }
   else{
   	  parent[v]=u;
   	  rank[u]+=rank[v];
   }
}

int kruskal(vector< pair<int,pair<int,int> > >g,int m){
   int i,j,k,l,n;
   int u,v,w,ans=0;   
   int rank[1000]={0};
   int parent[1000]={0};
   for(i=1;i<=m;i++){
      parent[i]=i;
      rank[i]=1;
   }
   for(i=0;i<g.size();i++){
       u=g[i].second.first;
       v=g[i].second.second;
       u=find(u,parent);
       v=find(v,parent);
       if(u!=v){
          ans+=g[i].first;
          unite(u,v,rank,parent);
       }
   }
   cout<<ans<<endl;
}

int main(int argc, char const *argv[])
{
	int i,j,k,l,m,n,u,v,w;
	vector< pair<int,pair<int,int> > >g;
	cin>>m>>n;
    for(i=0;i<n;i++){
    	cin>>u>>v>>w;
    	g.push_back(make_pair(w,make_pair(u,v)));
    }
    sort(g.begin(),g.end());
    kruskal(g,m);
	return 0;
}