#include <bits/stdc++.h>
using namespace std;

void input(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void preCompute(string pattern, int length, std::vector<int> &preArray){
	int i,j;
	j=0;
	preArray[0]=0;
	i=1;
	while(i<length){
		if(pattern[i]==pattern[j]){
			j++;
			preArray[i]=j;
			i++;
		}
		else{
			if(j!=0){
				j = preArray[j-1];
			}else{
				preArray[j]=0;
				i++;
			}
		}
	}
}

bool search(string text, string pattern){
	int i,j,k,l,m,n;
	m = text.length();
	n = pattern.length();
	std::vector<int> preArray(m+1,0);
	preCompute(pattern, n, preArray);
	 i=0;
	 j=0;
	 while(i<m){
	 	if(pattern[j]==text[i]){
	 		i++;
	 		j++;
	 	}
	 	if(j==n){
	 		cout<<"Found at "<< (i-j)<<endl;
	 		j = preArray[j-1];
	 	}
	 	else if(i<m && pattern[j]!=text[i]){
	 		if(j!=0){
	 			j=preArray[j-1];
	 		}else{
	 			i++;
	 		}
	 	}
	 }
}

int main(int argc, char const *argv[]){
	input();
	int i,j,k,l,m,n;
	string text, pattern;
	cin>>text>>pattern;
	search(text, pattern);
	return 0;
}