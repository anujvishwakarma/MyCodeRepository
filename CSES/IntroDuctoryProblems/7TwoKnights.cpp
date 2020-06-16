#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
	long long int i,n, totalWays, killingWays;
	cin>>n;
	for(i=1;i<=n;i++){
		totalWays = (i*i) * (i*i-1);
		totalWays/=2;
		killingWays = 4*(i-1)*(i-2); //knights kill each other 2 ways in board of 2*3 || 3*2;
		cout<<totalWays - killingWays<<endl;
	}
	return 0;
}