#include <bits/stdc++.h>
using namespace std;

int row[4]={0,0,-1,1};
int col[4]={1,-1,0,0};

int isSafe(int x,int y,int n,int m){
   if(x<n && y<m){
   	return 1;
   }
   return 0;
}

void dfs(int a[100][100],int x,int y,int n,int m,int c){
   if(a[x][y]!=c){
   	 return;
   }      
   a[x][y]++;
   int nextX,nextY;
   for(int i=0;i<4;i++){
     nextX=x+row[i];
     nextY=y+col[i];
     if(isSafe(nextX,nextY,n,m)){
     	dfs(a,nextX,nextY,n,m,c);
     }
   }
}

int main(int argc, char const *argv[])
{
	int i,j,k,l,m,n,x,y;
	int a[100][100];
	cin>>n>>m;
	for(i=0;i<n;i++){
     for(j=0;j<m;j++){
         cin>>a[i][j];
     }
	}
   cin>>x>>y;
   int colour=a[x][y];
   dfs(a,x,y,n,m,colour);
   for(i=0;i<n;i++){
     for(j=0;j<m;j++){
         cout<<a[i][j]<<" ";
     }
     cout<<endl;
	}
   return 0;
}