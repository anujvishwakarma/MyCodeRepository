#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int i,j,k,l,h,m,n;
	int a[100001];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>k;
    l=0;
    h=n-1;
    while(l<=h){
    	m=(l+h)/2;
    	if(a[m]==k){
    		cout<<"Found"<<endl;
    		return 0;
    	}
    	else if(a[m]>k){
    		h=m-1;
    	}
    	else{
    		l=m+1;
    	}
    }
    cout<<"Not Found"<<endl;
	return 0;
}