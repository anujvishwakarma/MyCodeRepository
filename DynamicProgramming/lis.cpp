#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	
	int i,j,k,m,n;
	int l[100001]={0};
	int a[100001]={0};
	string s1,s2;
	cin>>n;
    for(i=0;i<n;i++){
    	cin>>a[i];
    	l[i]=1;
    }
    int ans=0;
    for(i=1;i<n;i++){
    	for(j=0;j<i;j++){
            if(a[i]>a[j]){
            	l[i]=max(l[i],l[j]+1);
            	ans=max(ans,l[i]);
            }
    	}
    }
    cout<<ans<<endl;
	return 0;
}