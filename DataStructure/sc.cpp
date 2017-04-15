#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int k,a;
string A;
vector<int> V;
 
bool checkat(int m){
    int count=k;
    for(int i=V.size()-1;i>=0;i--){
        count-=V[i]/(m+1);
        if(count<0)
            return 0;
    }
    return 1;
}
 
int checkin(int l,int r){
    int m;
    while(l<r){
        m=(l+r)/2;
        if(checkat(m))
            r=m;
        else
            l=m+1;
    }
    return l;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n>>k;
	    cin>>A;
	    if(k>=(n-1)){
	        cout<<"1\n";
	        continue;
	    }
	    a=0;
	    for(int i=0;i<n;i++){
	        if(A[i]!=('0'+(i%2)))
	            a++;
	    }
	    if(a<=k ||(n-a)<=k){
	        cout<<"1\n";
	        continue;
	    }
	    a=0;
	    V.clear();
	    for(int i=1;i<n;i++){
	        if(A[i]!=A[i-1]){
	            if((i-a)>2)
    	            V.push_back(i-a);
	            a=i;
	        }
	    }
	    if((n-a)>2)
	        V.push_back(n-a);
	    if(V.empty()){
	        cout<<"2\n";
	        continue;
	    }
	    sort(V.begin(),V.end());
	    cout<<checkin(2,V[V.size()-1])<<endl;
	}
	return 0;
}
 
