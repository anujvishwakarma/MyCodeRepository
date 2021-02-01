#include <bits/stdc++.h>
using namespace std;

void input(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

int getStartingPoint(vector<pair<int,int> > petrolPump, int n){
	int i,j,k;
	int curr_petrol = petrolPump[0].first - petrolPump[1].second;
	int start = 0;
	int end = 1;
	while(start!=end || curr_petrol<0){
		while(curr_petrol<0 && start!=end){
			curr_petrol = curr_petrol - (petrolPump[start].first - petrolPump[start].second);
			start = (start+1)%n;
			if(start == 0){
				return -1;
			}
		}
		curr_petrol = curr_petrol + (petrolPump[start].first - petrolPump[start].second);
		end = (end+1)%n;
	}
	return start;
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	input();
	int petrol, distance;
	cin>>n;
	std::vector<pair<int,int> > petrolPump;
	for(i=0;i<n;i++){
		cin>>petrol>>distance;
		petrolPump.push_back(make_pair(petrol, distance));
	}
	int startNode = getStartingPoint(petrolPump, n);
	cout<<startNode+1<<endl;
	return 0;
}