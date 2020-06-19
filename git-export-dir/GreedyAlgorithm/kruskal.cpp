
/*
    This function uses stdc++ 11 version. So compile with -std=c++11
    or better include this header file <bits/stdc++.h> in your library. 
    ------May the spirit of Batman will always be with you------
    @author : Anuj Vishwakarma
*/


#include <bits/stdc++.h>
using namespace std;

/**** C function extension for fast in out *****/
#define scd(t) scanf("%d",&t)
#define scld(t) scanf("%ld",&lt)
#define sclld(t) scanf("%lld",&lt)
#define scc(t) scanf("%c",&t)
#define scs(t) scanf("%s",t)
#define scf(t) scanf("%f",&t)
#define sclf(t) scanf("%lf",&t)
/**********************************************/


#define mem(a,b) memset(a,b,sizeof(a))
#define fr(i,a) for(i=0;i<a;i++)
#define rfr(i,a) for(i=a;i>=0,i--)
#define fr2(i,a,b) for(int i=a;i<b;i++)
#define rfr2(i,a,b) for(int i=b;i>=a;i--)
#define foreach(it,l) for(auto it=l.begin();it!=l.end();it++)

/*********************************************/

/* C++ Utils */
#define mp make_pair
#define pb push_back
#define inf (int)1e9
#define eps 1e-9
#define mod 1000000007

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef map<string,int> msi;
typedef set<int>seti;
typedef multiset<int>mseti;

/*********************************************/
 

 /*DataType */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

/* Template of basic operation */ 
template< typename T,typename U> inline void amin(T &x,U y){if (y<x) x=y;}
template< typename T,typename U> inline void amax(T &x,U y){if (x<y) x=y;}

/*******************************************/


/* Debug Function */
#define pr(a) cout<<"debug is "<<a<<" ";
#define pr1(a) cout<<"debug is "<<a<<" "<<endl;
#define pr2(a,b) cout<<"debug is "<<a<<" "<<b<<endl;
#define pr3(a,b,c) cout<<"debug is "<<a<<" "<<b<<" "c<<" "endl;
#define nl cout<<endl;


void prm(int a[1001][1001],int x,int y){
  nl
  cout<<"########Debug Matrix########"<<endl;
   for(int i=0;i<x;i++){
     for(int j=0;j<y;j++){
         pr(a[i][j]);
     }
     nl;
   }
   nl;
  cout<<"############end#############"<<endl;
}
/******************************************/

/*****************. MAIN-CODE .*************************/

int parent[10000];
int path[10000];

int find(int u){
  while(u!=parent[u]){
    parent[u]=parent[parent[u]];  //path compression
    u=parent[u];
  }
  return u;
}

void merge(int u,int v){  //find by rank O(log(n));
    if(path[u]<path[v]){
       path[v]+=path[u];
       parent[u]=v;
    }
    else{
      path[u]+=path[v];
      parent[v]=u;
    }
}

void kruskal(vector< pair< pair<int,int>,int> >graph,int n){
  int i,j,k,l,m;
  int u,v,w;
  int cost=0;
  for(i=0;i<n;i++){
     u=graph[i].first.second;
     v=graph[i].second;
     w=graph[i].first.first;
     u=find(u);
     v=find(v);
     if(u!=v){
       cout<<"vertex included : "<<graph[i].first.second<<" "<<graph[i].second<<endl;
       cost+=w;
       merge(u,v);
     }
  }
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n,u,v,w;
  int a[1000001];
  vector< pair< pair<int,int>,int> >graph; //For a graph like {(w,u),v} w=weight
  cin>>n;
  for(i=0;i<n;i++){
   cin>>u>>v>>w;
   graph.push_back(make_pair(make_pair(w,u),v));
  }
  sort(graph.begin(),graph.end());
  for(i=0;i<=n;i++){
    parent[i]=i;
    path[i]=1;
  }
  kruskal(graph,n);
	return 0;
}

