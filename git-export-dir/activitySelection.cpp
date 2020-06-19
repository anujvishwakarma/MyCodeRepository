#include <bits/stdc++.h>
using namespace std;

bool compareMe(pair<int,int> a, pair<int,int> b){
   return (a.second < b.second);
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
    pair<int,int>p[1000];
    cin>>n;
    for(i=0;i<n;i++){
    	cin>>p[i].first;
    }
    for(i=0;i<n;i++){
    	cin>>p[i].second;
    }
    sort(p,p+n, compareMe);
    int count =1 ;
    int curr_finish = p[0].second;
    for(i=1;i<n;i++){
    	if(curr_finish<=p[i].first){
    		count++;
    		curr_finish=p[i].second;
    	}
    }
    cout<<count<<endl;
	return 0;
}
