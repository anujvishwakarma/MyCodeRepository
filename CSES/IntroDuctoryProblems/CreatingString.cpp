#include <bits/stdc++.h>
using namespace std;

set<string> myset;
void printAllPermutations(string s, int low, int high){
	int index;
	if(low==high){
		myset.insert(s);
		return;
	}
	for(index=low; index<=high; index++){
		swap(s[low], s[index]);
		printAllPermutations(s,low+1, high);
		swap(s[low], s[index]);
	}
}


int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	string s;
	cin>>s;
	printAllPermutations(s,0,s.length()-1);
	cout<<myset.size()<<endl;
	set<string> :: iterator it;
	for(it=myset.begin(); it!=myset.end();++it){
		cout<<*it<<endl;
	}
	return 0;
}