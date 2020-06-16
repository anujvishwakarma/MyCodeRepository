#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	long long int t,x,y, minValue, maxValue;
	cin>>t;
	while(t--){
		cin>>x>>y;
		minValue=min(x,y);
		maxValue=max(x,y);
		if(maxValue > 2*minValue){
			cout<<"NO"<<endl;
		}
		else if((minValue+maxValue)%3== 0){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}