#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
	long long int i,j,k,l,m,n;
	cin>>n;
	while(n--){
		cin>>i>>j;
		if(i>j){
			if(i%2==0){
				m=i*i-j+1;
			}else{
				i--;
				m=i*i + j;
			}
		}else{
			if(j%2==0){
				j--;
				m=j*j+i;
			}else{
				m=j*j-i+1;
			}
		}
		cout<<m<<" "<<endl;
	}
	return 0;
}