#include <bits/stdc++.h>
using namespace std;

vector<int> palin;

string getManipulatedData(string s){
	string newData = "@";
	for(int i=0;i<s.length();i++){
		newData += "#" + s.substr(i,1);
	}
	newData += "$";
	return newData;
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	string data;
	cin>>data;

	string newData = getManipulatedData(data);
	int center =0, right =0;
	n = newData.length();
	palin.assign(n+1,0);

	for(i=1;i<n;i++){
		int mirror_index = 2*center - i;

		//Case1 --> if palindrome is under the boundry
		if(i < right) {
			palin[i] = min( palin[mirror_index] , right -i);
		}

		//Case2 --> expand the palindrome
		while(newData[i+palin[i]+1] == newData[i-palin[i] - 1] ){
			palin[i]++;
		}

		//Case3 --> if palindrome is beyond the boundry
		if(i+palin[i] > right){
			center = i ;
			right = i+ palin[i];
		}
	}

	int ans = 1;
	for(i=0;i<palin.size();i++){
		ans=max(ans, palin[i]);
	}
	cout<<"longest palindrome is "<< ans<<endl;
	return 0;
}