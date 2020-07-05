#include <bits/stdc++.h>
using namespace std;

int x[]={1,-1,0,0};
int y[]={0,0,1,-1};

void dfs(string graph[1001], int i, int j, int n, int m, vector<std::vector<bool>> &visit){
	visit[i][j]=true;
	for(int k=0;k<4;k++){
		int nextX = i + x[k];
		int nextY = j + y[k];
		if(nextX>=0 && nextX<n && nextY>=0 && nextY<m) {
			if(!visit[nextX][nextY] && graph[nextX][nextY]=='.'){
				dfs(graph, nextX, nextY, n, m, visit);
			}
		}
	}
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	string graph[1001];
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>graph[i];
	}
	int ans =0;
	vector<std::vector<bool>> visit(n, std::vector<bool> (m, false));
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(graph[i][j]=='.' && !visit[i][j]){
				ans++;
				dfs(graph, i, j, n, m, visit);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}