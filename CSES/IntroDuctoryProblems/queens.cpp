#include <bits/stdc++.h>
using namespace std;

std::vector<int> col(16,0);
std::vector<int> diag1(16,0);
std::vector<int> diag2(16,0);

vector<vector<int>> v(8, vector<int> (8,0));

int ans=0;


void solve(int curr_row){
	if(curr_row==8){
		ans++;
		return;
	}
	int column;
	for(column=0; column <8; column++){
		if(col[column] || diag1[curr_row+ column] || 
			diag2[curr_row-column+7] || v[curr_row][column]){
			continue;
		}
		col[column] = diag1[curr_row+ column] = diag2[curr_row-column+7] = 1;
		solve(curr_row+1);
		col[column] = diag1[curr_row+ column] = diag2[curr_row-column+7] = 0;

	}
}

int main(int argc, char const *argv[]){
	
	int i,j,k,l,m,n;
	string s[8];
	for(i=0;i<8;i++){
		cin>>s[i];
		for(j=0;j<8;j++){
			if(s[i][j]=='*'){
				v[i][j]=1;
			}
		}
	}
	solve(0);
	cout<<ans<<endl;
	return 0;
}