#include <bits/stdc++.h>
using namespace std;

bool searchValue(vector<int> input, int size, int value){
    for(int i=0;i<size; i++){
        if(input[i]==value){
            return 1;
        }
    }
    return false;
}

int main(int argc, char const *argv[]) {
    int i,j,k,l,m,n;
    vector<int> input;
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>k;
        input.push_back(k);
    }
    bool isFound = searchValue(input, n, m);
    cout<<isFound<<endl;
    return 0;
}