#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	string s;
	getline(cin,s);
	int a[26]={0};
	for(i=0;i<s.length();i++){
		a[s[i]-'a']++;
	}
	int evenCount =0, oddCount =0;
	for(i=0;i<26;i++){
		if(a[i]%2){
			oddCount++;
		}else{
			evenCount++;
		}
	}
	if(oddCount==0 || oddCount ==1){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<std::endl;
	}
	return 0;
}
