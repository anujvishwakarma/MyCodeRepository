#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	long long int n;
	cin>>n;
	while(n!=1){
		cout<<n<<endl;
		if(n%2){
			n=n*3+1;
		}else{
			n=n/2;
		}
	}
	cout<<n<<endl;
	return 0;
}