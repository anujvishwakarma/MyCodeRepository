#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
    long long int n,k,ans=0, delimiter = 5;
    cin>>n;
    while(1){
        k=n/delimiter;
        if(k){
            ans+=k;
        }else{
            break;
        }
        delimiter*=5;
    }
    cout<<ans<<endl;
    return 0;
}