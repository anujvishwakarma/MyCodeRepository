#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
	int i,j,n;
	string s;
	long long int ans=1,curr=1;
	cin>>s;
	n = s.length();
	for(i=1;i<n;i++){
		if(s[i]==s[i-1]){
			curr++;
			ans = max(ans, curr);
		}else{
			curr=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}