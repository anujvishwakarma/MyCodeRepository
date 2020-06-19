#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
    int i,j,k,l,m,n;
    string s1,s2;
    cin>>s1>>s2;
    s1 = s1 + s1;
    for(i=0;i<s1.length();i++){
    	int count =0;
   		j=0,k=i;
   		if(s1[i] == s2[j]){
   			while(s1[i] == s2[j]){
   				count++;
   				i++;
   				j++;
   			}
   			if(j== s2.length()){
   				cout<<"true"<<endl;
   				return 0;
   			}
   		}
   		i=k;
    }
    cout<<"No"<<endl;
	return 0;
}