
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


struct node
{
    int value;
    struct node *next;
};

struct node *insert(struct node *start,int k){
    struct node *tmp=(struct node *)malloc(sizeof(struct node ));
    tmp->value=k;
    tmp->next=NULL;
    if(start==NULL){
      return tmp;
    }
    struct node *head=start;
    while(head->next!=NULL){
      head=head->next;
    }
    head->next=tmp;
    return start;
}

void print(struct node *start){
     while(start!=NULL){
        cout<<start->value<<" ";
        start=start->next;
     }
}

struct node *inverse(struct node *start){
   struct node *curr=start;
   struct node *prev=NULL;
   struct node *nextlink=NULL; 
   while(curr!=NULL){
       nextlink=curr->next;
       curr->next=prev;
       prev=curr;
       curr=nextlink;
   }
   return prev;
}

int main(int argc, char const *argv[])
{
	int i,j,k,l,m,n;
  cin>>n;
  struct node *start=NULL;
  
  for(i=0;i<n;i++){
       cin>>k;
       start=insert(start,k);
  }
  print(start);
  cout<<endl;
  struct node *inversStart=start;
  inversStart= inverse(inversStart);
  print(inversStart);
	return 0;
}







































