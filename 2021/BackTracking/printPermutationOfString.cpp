#include <bits/stdc++.h>
using namespace std;

void printAllPermute(string s, int low, int high){
	if(low==high){
		cout<<s<<endl;
	}
	for(int i=low;i<=high;i++){
		swap(s[i],s[low]);
		printAllPermute(s, low+1, high);
		swap(s[i],s[low]);
	}
}


int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	string s;
	cin>>s;
	printAllPermute(s,0,s.length()-1);
	return 0;
}