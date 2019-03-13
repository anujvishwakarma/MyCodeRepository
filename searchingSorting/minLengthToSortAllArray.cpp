
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





int main(int argc, char const *argv[])
{

	int i,j,k,l,m,n;
  int a[1000001];
  cin>>n;
  for(i=0;i<n;i++){
    cin>>a[i];
  }
  i=0,j=0;
  int s=-1,e=-1;
  for(i=0;i<n-1;i++){
    if(a[i]>a[i+1]){
        s=i;
        break;
    }
  }
 if(s==-1){
  cout<<"Already sorted"<<endl;
  return 0;
 }
 for(i=n-1;i>=1;i--){
   if(a[i]<a[i-1]){
    e=i;
    break;
   }
 }

 int minvalue=a[s];
 int maxvalue=a[s];
 for(i=s;i<=e;i++){
   minvalue=min(a[i],minvalue);
   maxvalue=max(a[i],maxvalue);
 }

for(i=0;i<s-1;i++){
  if(a[i]>minvalue){
     s=i;
     break;
  }
}

for(i=n-1;i>e;i--){
  if(a[i]<maxvalue){
     e=i;
     break;
  }
}

cout<<s<<" "<<e<<endl;
	return 0;
}





















