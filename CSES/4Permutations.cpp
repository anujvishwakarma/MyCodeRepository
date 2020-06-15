#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	cin>>n;
	if(n==1){cout<<"1"<<endl; return 0;}
	if(n==4){
		cout<<"2 4 1 3"<<endl; 
		return 0;
	}
	if(n==2 || n==3){
		cout<<"NO SOLUTION"<<endl;
	}else{
		m = n;
		k = n-1;
		while(m>0){
			cout<<m<<" ";
			m=m-2;
		}
		while(k>0){
			cout<<k<<" ";
			k=k-2;
		}
	}
	cout<<endl;
	return 0;
}