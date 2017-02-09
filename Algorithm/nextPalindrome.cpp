#include <bits/stdc++.h>
using namespace std;
int allGo(string s){
	int c=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='9'){
			c++;
		}
	}
	if(c==s.length()){
		return 1;
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	int i,j,k,l,m,n;
	int a[100001];
	string s;
	cin>>s;
	if(allGo(s)){
      cout<<"1";
      for(i=0;i<s.length()-1;i++){
      	cout<<"0";
      }
      cout<<"1";
      return 0;
	}
	n=s.length();
	m=n/2;
	i=m-1;
	j=(n%2)?m+1:m;
	while(i>=0 && s[i]==s[j]){
		i--;
		j++;
	}
   int copyFlag=0;
   if(i<0||s[i]<s[j]){
      copyFlag=1;
   }
   while(i>=0){
   	s[j]=s[i];
   	j++;i--;
   }

   if(copyFlag==1){
     int c=1;
     i=m-1;
     if(n%2==1){
        k=s[m]-'0'+c;
        c=k/10;
        k=k%10;
        s[m]='0'+k;
        j=m+1;
     } 
     else{
     	j=m;
     }
     while(i>=0){
     	k=s[i]-'0'+c;
     	c=k/10;
     	k=k%10;
     	s[i]='0'+k;
     	s[j++]=s[i--];
     }

   }
  cout<<s<<endl;


	return 0;
}