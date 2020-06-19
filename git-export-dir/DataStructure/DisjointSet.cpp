
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


#define mem(a,b) memset(a,b,sizeif(a))
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
#define pr(a) cout<<a<<" ";
#define pr1(a) cout<<a<<" "<<endl;
#define pr2(a,b) cout<<a<<" "<<b<<endl;
#define pr3(a,b,c) cout<<a<<" "<<b<<" "c<<" "endl;
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

int find(int x,int parent[10000]){
  int i;
  while(x!=parent[x]){
      x=parent[x];
  }
  return x;
}

 void unite(int x,int y,int parent[10000]){
     parent[x]=y;
 }
bool isCycle(std::vector< pair<int,int> > v,int parent[100],int vertex,int n){
    int i,j,k,l;
    for(i=0;i<v.size();i++){
       int x=v[i].first;
       int y=v[i].second;
       x=find(x,parent);
       y=find(y,parent);
       if(x==y){
          cout<<"cycle detect at "<<v[i].first<< " "<<v[i].second<<endl;
          return true;
       }
       else{
         unite(x,y,parent);
       }
    }
  return false;
}

int main(int argc, char const *argv[])
{

	int i,j,k,l,m,n,x,y;
  int a[10000];
  vector< pair<int,int> > v;
  int parent[10001];
  cin>>n>>m;
  for(i=0;i<n;i++){
      parent[i]=i;
  }
  for(i=0;i<m;i++){
     cin>>x>>y;
     v.push_back(make_pair(x,y));
  }
  bool value=isCycle(v,parent,1,n);
  if(value==true){
    cout<<"Cycle exist"<<endl;
    return 1;
  }
  cout<<"safe"<<endl;
	return 0;
}







































