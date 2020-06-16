#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	long long int i,x,y,n, curr =0, ans=0;
	std::vector<pair<long long int , long long int >> data;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>x>>y;
		data.push_back(make_pair(x,1));
		data.push_back(make_pair(y,-1));
	}
	sort(data.begin(), data.end());
	n=data.size();
	for(i=0;i<n;i++){
		if(data[i].second>0){
			curr++;
		}else{
			curr--;
		}
		ans=max(ans,curr);
	}
	cout<<ans<<endl;
	return 0;
}