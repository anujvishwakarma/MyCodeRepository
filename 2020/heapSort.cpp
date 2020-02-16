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


void heapify(std::vector<int> &v, int n, int index){
	int i,j,k;
	int left=2*index+1;
	int right=2*index+2;
	int largest = index;
	if(left<n && v[left] > v[largest]){
		largest=left;
	}
	if(right<n && v[right] > v[largest]){
		largest=right;
	}
	if(largest!=index){
		swap(v[index], v[largest]);
		heapify(v,n,largest);
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
	for(i=(n/2)-1;i>=0;i--){
		heapify(v,n,i);
	}
	for(i=n-1;i>=0;i--){
		swap(v[0],v[i]);
		heapify(v,i,0);
	}
	printA(v);
	return 0;
}