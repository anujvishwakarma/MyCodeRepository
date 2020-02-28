#include <bits/stdc++.h>
using namespace std;


/* TestCase
8
10 22 9 33 21 50 41 60
*/
int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	std::vector<int> v;
	std::vector<int> lis;
	cin>>n;
	int ans=1;
	for(i=0;i<n;i++){
		cin>>k;
		v.push_back(k);
		lis.push_back(1);
	}
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			if(v[j]<v[i] && lis[i]<lis[j]+1){
				ans=max(ans,lis[i]=lis[j]+1);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}