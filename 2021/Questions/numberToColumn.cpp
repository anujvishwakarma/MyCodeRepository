#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	cin>>n;
	int rem;
	string ans="";
	while(n){
		rem=n%26;
		if(rem==0){
			n=n/26 - 1    ;
			ans+="Z";
		}else{
			ans+=(rem-1)+'A';
			n=n/26;
		}
	}
	reverse(ans.begin(), ans.end());
	cout<<ans<<endl;	
	return 0;
}