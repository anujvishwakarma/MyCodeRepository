#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	string s, ans = "";
	string dna = "ACGT";
	set<char> myset;
	cin>>s;
	n=s.length();
	for(i=0;i<n;i++){
		myset.insert(s[i]);
		if(myset.size()==4){
			ans=ans+s[i];
			myset.clear();
		}
	}
	for(i=0;i<4;i++){
		if(myset.count(dna[i])==0){
			ans=ans+dna[i];
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}