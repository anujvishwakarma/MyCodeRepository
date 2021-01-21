#include <bits/stdc++.h>
using namespace std;

float getPower(int x, int y){
	if(y==0){
		return 1;
	}
	float temp = getPower(x, y/2);
	if(y%2 == 0){
		return temp * temp;
	}
	if(y>0){
		return x * temp * temp;
	}else{
		return (temp*temp)/x;
	}
	return 0.0;
}

int main(int argc, char const *argv[]){
	int i,j,k,l;
	float n,m;
	cin>>n>>m;
	float ans = getPower(n,m);
	cout<<ans<<endl;
	return 0;
}