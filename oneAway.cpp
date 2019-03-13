#include <bits/stdc++.h>
using namespace std;

bool isOneAway(string s1, string s2){
	if(abs((int)s1.length() - (int)s2.length()) > 1){
		return false;
	}
	string smaller = s1.length() > s2.length() ? s2 : s1;
	string bigger = s1.length() > s2.length() ? s1 : s2;
	int i=0,j=0;
	bool mismatch = false;
	while( i < smaller.length() && j<bigger.length()){
		if(smaller[i]!=bigger[j]){
			if(mismatch){
				return false;
			}
			mismatch = true;
			if(smaller.length() == bigger.length()){
				i++;
			}
		}else{
			i++;
		}
		j++;
	}
	return true;
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	string s1,s2;
	cin>>s1>>s2;
	bool canEdit = isOneAway(s1,s2);
	cout<<(canEdit ? "true" : "false")<<endl;
	return 0;
}