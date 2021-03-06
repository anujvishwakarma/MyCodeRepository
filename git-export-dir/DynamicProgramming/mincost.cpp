
/*
    This function uses stdc++ 11 version. So compile with -std=c++11
    or better include this header file <bits/stdc++.h> in yout library. 
    ------May the spirit of Batman will always with you------
    Author : Anuj Vishwakarma
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
#define rfr2(i,a,b) for(int i=b-1;i>=a;i--)
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


#define pr(a) cout<<a<<" ";
#define pr1(a) cout<<a<<" "<<endl;
#define nl cout<<endl;
#define pr2(a,b) cout<<a<<" "<<b<<endl;
#define pr3(a,b,c) cout<<a<<" "<<b<<" "c<<" "endl;


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


int main(int argc, char const *argv[])
{
  int i,j,k,l,m,n;
  int a[1001][1001]={0};
  int dp[1001][1001]={0};
  cin>>m>>n;
  fr(i,n){
    fr(j,m){
       cin>>a[i][j];
    }
  }
  dp[0][0]=a[0][0];
  for(i=1;i<n;i++){
     dp[i][0]=dp[i-1][0]+a[i][0];
  }
  
  for(i=1;i<m;i++){
    dp[0][i]=dp[0][i-1]+a[0][i];
  }

  for(i=1;i<n;i++){
    for(j=1;j<m;j++){
       dp[i][j]=min(dp[i-1][j],dp[i][j-1])+a[i][j];
    }
  }

  prm(dp,n,m);
  pr1(dp[n-1][m-1]);

  return 0;
}







































