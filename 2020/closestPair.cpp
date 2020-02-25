#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	int i,j,k,x,l,m,n;
	std::vector<int> v;
	cin>>n>>x;
	for(i=0;i<n;i++){
		cin>>k;
		v.push_back(k);
	}
	sort(v.begin(),v.end());
	l=0;
	int r=n-1;
	pair<int,int>ans;
	int curr_ans=v[r]+v[l]-x;
	while(l<r){
		if((v[r]+v[l]-x)<curr_ans){
			ans.first=v[l];
			ans.second=v[r];
			curr_ans=v[r]+v[l]-x;
		}
		if(v[r]+v[l]-x < 0){
			l++;
		}
		else{
			r--;
		}
	}
	cout<<curr_ans<<endl;
	cout<<"Pair are "<<ans.first<<" "<<ans.second<<endl;
	return 0;
}
