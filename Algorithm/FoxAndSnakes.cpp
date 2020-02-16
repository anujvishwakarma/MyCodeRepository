#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int i,j,k,l,m,n;
	cin>>n>>m;
	int f=m-1;
	k=0;
	for(i=1;i<=n;i++){
      if(i%2){
      	for(j=1;j<=m;j++){
      		cout<<"#";
      	}
      }
      else{
      	if(k==0){
           for(j=1;j<m;j++){
      		cout<<".";
      	    }
      	    cout<<"#";
      	}
      	else{
      		cout<<"#";
			for(j=1;j<m;j++){
      		cout<<".";
      	    }
      	}
      	k=(k+1)%2;
      }
      cout<<endl;
	}
	return 0;
}