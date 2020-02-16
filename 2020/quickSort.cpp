#include <bits/stdc++.h>
using namespace std;

void printA(std::vector<int> &v){
	int i;
	for(i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

#define pr1(a) cout<<"debug is "<<a<<" "<<endl;
#define pr2(a,b) cout<<"debug is "<<a<<" "<<b<<endl;
#define pr3(a,b,c) cout<<"debug is "<<a<<" "<<b<<" "<<c<<" "<<endl;

int getPivot(std::vector<int> &v, int l, int h){
	int i,j,k;
	i=l-1;
	int pivotElement = v[h];
	for(j=l;j<h;j++){
		if(v[j]<pivotElement){
			i++;
			swap(v[i],v[j]);
		}
	}
	swap(v[i+1],v[h]);
	return i+1;
}

void quickSort(vector<int> &v, int l, int h){
	if(l<h){
		int p = getPivot(v,l,h);
		quickSort(v,l,p-1);
		quickSort(v,p+1,h);
	}
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	std::vector<int> v;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>k;
		v.push_back(k);
	}
	quickSort(v,0,n-1);
	printA(v);
	return 0;
}