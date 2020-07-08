#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(int argc, char const *argv[]){
	long long int i,j,k,l,m,n,q,u,v,w;
	cin>>n>>m>>q;
	std::vector<std::vector<ll> > distance(n+1, std::vector<long long> (n+1, 1e18));
	for(i=0;i<m;i++){
		cin>>u>>v>>w;
		if(w < distance[u][v]){
			distance[u][v] = distance[v][u] = w;
		}
	}

	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				long long int curr_distance = distance[i][k] + distance[k][j];
				distance[i][j] = distance[j][i] = min(curr_distance, distance[i][j]);
			}
		}
	}

	while(q--){
		cin>>u>>v;
		if(u==v){
			distance[u][v] =0;
		}
		else if(distance[u][v] == 1e18){
			distance[u][v]=-1;
		}
		cout<<distance[u][v]<<endl;
	}
	return 0;
}