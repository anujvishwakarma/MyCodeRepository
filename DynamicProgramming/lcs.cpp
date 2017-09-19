#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int i,j,k,l,m,n;
	int a[101][101];
	string s1,s2;
    cin>>s1>>s2;
    int l1=s1.length();
    int l2=s2.length();
    for(i=0;i<=l1;i++){
       for(j=0;j<=l2;j++){
       	  if(i==0||j==0){
       	  	a[i][j]=0;
       	  }
       	  else{
       	  	if(s1[i-1]==s2[j-1]){
       	  		a[i][j]=a[i-1][j-1]+1;
       	  	}
       	  	else{
       	  		a[i][j]=max(a[i-1][j],a[i][j-1]);
       	  	}
       	  }
       }
    }
    cout<<a[l1][l2]<<endl;
	return 0;
}