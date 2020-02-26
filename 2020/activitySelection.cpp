#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int,int> &a, const pair<int,int> &b){
	return a.second<b.second;
}

void getIntervals(std::vector<pair<int,int> >v, int n){
	int i=0,j=0;
	sort(v.begin(),v.end(),compare);
	cout<<v[0].first<<" "<<v[0].second<<endl;
	int finishTime=v[0].second;
	for(i=1;i<n;i++){
		if(v[i].first>=finishTime){
			cout<<v[i].first<<" "<<v[i].second<<endl;
			finishTime=v[i].second;
		}
	}
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	std::vector<pair<int,int> >v;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>j>>k;
		v.push_back(make_pair(j,k));
	}
	getIntervals(v,n);
	return 0;
}