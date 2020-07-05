#include <bits/stdc++.h>
using namespace std;

int x[]={1,-1,0,0};
int y[]={0,0,1,-1};
string path = "DURL";
map<pair<int,int>, pair<pair<int,int>, char> > parentMap;

void createPath(string graph[1001],int i, int j, int curr_x, int curr_y){
	string pathData = "";
	pair<pair<int,int>, char> dest = parentMap[make_pair(curr_x,curr_y)];

	//cout<<"Main Dest --> "<<curr_x<<" "<<curr_y<<endl;
	while(true){
		curr_x = dest.first.first;
		curr_y = dest.first.second;
	//	cout<<"Dest --> "<<curr_x<<" "<<curr_y<<" --> "<<dest.second<<endl;

		if(i==curr_x && j==curr_y){
			pathData+=dest.second;
			break;
		}
		pathData+=dest.second;
		dest = parentMap[make_pair(curr_x,curr_y)];
	}
	reverse(pathData.begin(), pathData.end());
	cout<<pathData<<endl;
}

void bfs(string graph[1001], int i, int j, int n, int m, vector<std::vector<bool>> &visit){
	int k, ans;
	bool flag = false;

	queue<pair<pair<int,int> , int>> myQueue;
	myQueue.push(make_pair(make_pair(i,j),0));
	visit[i][j]=true;

	int pathx, pathy;
	while(!myQueue.empty()){
		pair<pair<int,int> , int> temp = myQueue.front(); myQueue.pop();
		int curr_x = temp.first.first;
		int curr_y = temp.first.second;
		int curr_distance = temp.second;

		//cout<<"curr value --> "<<curr_x<<" "<<curr_y<<" dist --> "<<curr_distance<<endl;

		if(graph[curr_x][curr_y] == 'B'){
			pathx = curr_x;
			pathy = curr_y;
			flag  = true;
			ans = curr_distance;
			break;
		}	
		for(k=0;k<4;k++){
			int nextX = curr_x + x[k];
			int nextY = curr_y + y[k];
			if(nextX<n && nextX>=0 && nextY<m && nextY>=0){
				if(!visit[nextX][nextY] && (graph[nextX][nextY]=='.' || graph[nextX][nextY]=='B')){
					//cout<<"next Path -> "<<nextX<<" "<<nextY<<" -->"<< path[k]<<endl;
					parentMap[make_pair(nextX, nextY)] = make_pair(make_pair(curr_x, curr_y), path[k]);
					visit[nextX][nextY] = true;
					myQueue.push(make_pair(make_pair(nextX, nextY), curr_distance+1));
				}
			}
		}
	}

	if(flag){
		cout<<"YES"<<endl;
		cout<<ans<<endl;
		createPath(graph,i, j, pathx, pathy);
	}else{
		cout<<"NO"<<endl;
	}
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	string graph[1001];
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>graph[i];
	}
	vector<std::vector<bool>> visit(n, std::vector<bool> (m, false));
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(graph[i][j]=='A'){
				bfs(graph, i, j, n, m, visit);
				break;
			}
		}
	}
	return 0;
}