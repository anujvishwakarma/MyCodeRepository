#include <bits/stdc++.h>
using namespace std;

void input(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}


void inc(int *i){
	(*i)++;
}

int main(int argc, char const *argv[]){
	input();
	int i =0;
	for(i=0;i<6;i++){
		inc(&i);
	}
			cout<<i<<endl;

	return 0;
}