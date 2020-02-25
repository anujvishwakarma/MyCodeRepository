#include<bits/stdc++.h>
using namespace std;
void getCommonElements(vector<int> v1, vector<int> v2, vector<int> v3){
	int n1,n2,n3;
	int l1=0,l2=0,l3=0;
	n1=v1.size();
	n2=v2.size();
	n3=v3.size();
	std::vector<int> ans;
	while(l1<n1 && l2<n2 && l3<n3){
		if(v1[l1]==v2[l2] && v2[l2]==v3[l3]){
			cout<<v1[l1]<<" ";
			l1++;l2++;l3++;
		}
		else if(v1[l1]<v2[l2]){
			l1++;
		}
		else if(v2[l2]<v3[l3]){
			l2++;
		}
		else {
			l3++;
		}
	}
}

int main(int argc, char const *argv[]){
	int i,j,k;
	int n1,n2,n3;
	std::vector<int> v1;
	std::vector<int> v2;
	std::vector<int> v3;
	cin>>n1>>n2>>n3;
	for(i=0;i<n1;i++){
		cin>>k;
		v1.push_back(k);
	}
	for(i=0;i<n2;i++){
		cin>>k;
		v2.push_back(k);
	}
	for(i=0;i<n3;i++){
		cin>>k;
		v3.push_back(k);
	}
	getCommonElements(v1,v2,v3);
	return 0;
}