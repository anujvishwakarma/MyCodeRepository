#include <bits/stdc++.h>
using namespace std;

int row[4] = {0,1,-1,0};
int col[4] = {1,0,0,-1};

bool isSafe(vector<vector<int>> &data, int nextX, int nextY, int n, int m){
	if(nextX>=0 && nextX<n && nextY>=0 && nextY<m){
		return (data[nextX][nextY]==1);
	}
	return false;
}

bool runTheMouse(vector<vector<int>> &data, int currX, int currY, int n, int m){
	if(currX == n-1 && currY ==m-1){
		data[currX][currY]= 2;
		return true;
	}
	for(int i=0;i<4;i++){
		int nextX = currX+row[i];
		int nextY = currY+col[i];
		if(isSafe(data, nextX, nextY, n, m)){
			data[nextX][nextY] = 2;
			if(runTheMouse(data, nextX, nextY, n , m)){
				return true;
			}
			data[nextX][nextY] = 1;
		}
	}
	return false;
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	cin>>n>>m;
	std::vector<std::vector<int>> data(n, std::vector<int> (m));
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin>>data[i][j];
		}
	}
	data[0][0]=2;
	bool isPossible = runTheMouse(data, 0, 0, n, m);
	cout<<isPossible<<endl;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cout<<data[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}