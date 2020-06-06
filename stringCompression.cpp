#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	string s;
	cin>>s;
	int count = 1;
	for(i=0;i<s.length();i++){
		count = 1;
		while(i<s.length()-1 && (s[i] == s[i+1])){
			count++;
			i++;
		}
		cout<<s[i]<<count;
	}
	cout<<endl;
	return 0;
}