#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int,int> &a, const pair<int,int> &b){
	return a.second < b.second;
}

void printIntervals(std::vector<pair<int,int>> &data, int n){
	int i;
	cout<<"Activity Allowed"<<endl;
	cout<<data[0].first<<" "<<data[0].second<<endl;
	int finishTime = data[0].second;
	for(i=1;i<n;i++){
		if(data[i].first>finishTime){
			cout<<data[i].first<<" "<<data[i].second<<endl;
			finishTime = data[i].second;
		}
	}
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	std::vector<pair<int,int>> data;
	cin>>n;
	int start, finish;
	for(i=0;i<n;i++){
		cin>>start>>finish;
		data.push_back(make_pair(start, finish));
	}
	sort(data.begin(), data.end(), compare);
	printIntervals(data, n);
	return 0;
}