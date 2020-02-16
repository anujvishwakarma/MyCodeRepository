#include <bits/stdc++.h>
using namespace std;


#define pr1(a) cout<<"debug is "<<a<<" "<<endl;
#define pr2(a,b) cout<<"debug is "<<a<<" "<<b<<endl;
#define pr3(a,b,c) cout<<"debug is "<<a<<" "<<b<<" "<<c<<" "<<endl;

void printA(std::vector<int> &v){
	int i;
	for(i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

void mergeThem(vector<int> &v, int l, int m, int h){
	int i,j,k;
	int l1 = m-l+1;
	int l2 = h-m;
	std::vector<int> first;
	std::vector<int> second;
	for(i=0;i<l1;i++){
		first.push_back(v[l+i]);
	}
	for(i=0;i<l2;i++){
		second.push_back(v[m+1+i]);
	}
	i=0;j=0;
	k=l;
	while(i< l1 && j<l2){
		if(first[i]<=second[j]){
			v[k]=first[i];
			i++;
		}else{
			v[k]=second[j];
			j++;
		}
		k++;
	}
	while(i<l1){
		v[k]=first[i];
		i++;k++;
	}
	while(j<l2) {
	    /* code */
	    v[k]=second[j];
	    j++;k++;
	}
}

void mergeSort(vector<int> &v, int l, int h){
	if(l<h){
		int m=(l+h)/2;
		mergeSort(v,l,m);
		mergeSort(v,m+1,h);
		mergeThem(v,l,m,h);
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
	mergeSort(v,0,n-1);
	for(i=0;i<n;i++){
		cout<<v[i]<<" ";
	}
	return 0;
}