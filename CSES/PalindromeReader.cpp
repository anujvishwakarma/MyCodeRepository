#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
	int i,n;
	string s;
	std::vector<int> hash(26,0);
	cin>>s;
	n=s.length();
	for(i=0;i<n;i++){
		hash[s[i]-'A']++;
	}
	int oddCount=0;
	for(i=0;i<26;i++){
		if(hash[i]%2){
			oddCount++;
		}
	}
	if(oddCount>1){
		cout<<"NO SOLUTION"<<endl;
		return 0;
	}
	string oddChar="";
	string temp="";
	for(i=0;i<26;i++){
		if(hash[i]%2){
			oddChar+=hash[i];
		}
		int count=hash[i]/2;
		while(count--){
			temp+=hash[i];
		}
	}
	string temp2 = temp;
	reverse(temp2.begin(), temp2.end());
	temp=temp+oddChar+temp2;
	cout<<temp<<endl;
	return 0;
}