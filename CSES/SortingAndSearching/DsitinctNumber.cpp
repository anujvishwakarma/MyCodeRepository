#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
	long long int n,i,k;
	set<long long int> myset;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>k;
		myset.insert(k);
	}
	cout<<myset.size()<<endl;
	return 0;
}