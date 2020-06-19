#include <bits/stdc++.h>
using namespace std;
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


#define pr1(a) cout<<"debug is "<<a<<" "<<endl;
#define pr2(a,b) cout<<"debug is "<<a<<" "<<b<<endl;
#define pr3(a,b,c) cout<<"debug is "<<a<<" "<<b<<" "c<<" "endl;


bool bin(vector<int> v, int l, int h, int x){
	if(l<=h){
		int m = (l+h)/2;
		if(v[m]==x){
			return true;
		}
		else if(v[m]>x){
			return bin(v,l,m-1,x);
		}else{
			return bin(v,m+1,h,x);
		}
	}
	return false;
}

int main(int argc, char const *argv[]){
	int i,j,x,k,l,m,n;
	std::vector<int> v;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>k;
		v.push_back(k);
	}

	cin>>x;
	if(bin(v,0,n-1,x)){
		cout<<"Found"<<endl;
	}else{
		cout<<"Not Found"<<endl;
	}
	return 0;
}