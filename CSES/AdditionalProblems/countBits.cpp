#include <bits/stdc++.h>
using namespace std;

int getSetBitsFromOneToN(long long int N){ 
    long long int two = 2,ans = 0; 
    long long int n = N; 
    while(n){ 
        ans += (N/two)*(two>>1); 
        if((N&(two-1)) > (two>>1)-1) ans += (N&(two-1)) - (two>>1)+1; 
        two <<= 1; 
        n >>= 1; 
    } 
    return ans; 
} 

int main(int argc, char const *argv[]){
	long long int i,j,k,l,m,n;
	cin>>n;
	cout<<getSetBitsFromOneToN(n)<<endl;
	return 0;
}