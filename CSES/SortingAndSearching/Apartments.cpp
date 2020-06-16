#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
	long long int i,j,n,m,k, value;
	std::vector<long long int> apartments, people;
	cin>>n>>m>>k;
	for(i=0;i<n;i++){
		cin>>value;
		apartments.push_back(value);
	}
	sort(apartments.begin(), apartments.end());
	for(i=0;i<m;i++){
		cin>>value;
		people.push_back(value);
	}
	sort(people.begin(), people.end());
	long long int index =0, ans=0 ;
	i=0;
	while(i<n && index<m){
		if(apartments[i]<= (people[index]+k) && 
				apartments[i]>= (people[index]-k)){
				ans++;
				index++;
				i++;
			}else if(apartments[i] > (people[index]+k)){
				index++;
			}else{
				i++;
			}
	}
	cout<<ans<<endl;
	return 0;
}