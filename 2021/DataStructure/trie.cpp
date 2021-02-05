#include <bits/stdc++.h>
using namespace std;

void input(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

struct node {
	bool isLeaf;
	struct node *children[26];
};

struct node *insert(struct node *trie, string s, int length){
	int i,j;
	struct node *run = trie;
	for(i=0;i<length;i++){
		int index = s[i]-'a';
		if(!run->children[index]){
			struct node *temp = (struct node *)malloc(sizeof(struct node));
			for(j=0;j<26;j++){
				temp->children[j]=NULL;
			}
			temp->isLeaf = false;
			run->children[index] = temp;
		}
		run = run->children[index];
	}
	run->isLeaf = true;
	return trie;
}


bool searchTrie(struct node *trie, string s, int length){
	int i,j;
	struct node *run = trie;
	for(i=0;i<length;i++){
		int id = s[i]-'a';
		if(!run->children[id]){
			return false;
		}
		run = run->children[id];
	}
	return (run!=NULL && run->isLeaf);
}

int main(int argc, char const *argv[]){
	input();
	int i,j,k,l,m,n;
	cin>>n;
	string s;
	struct node *trie = (struct node *)malloc(sizeof(struct node));
	for(i=0;i<26;i++){
		trie->children[i]=NULL;
	}
	trie->isLeaf = false;
	for(i=0;i<n;i++){
		cin>>s;
		trie = insert(trie, s, s.length());
	}

	cin>>s;
	bool isFound = searchTrie(trie, s, s.length());
	
	cout<<s<<" --> "<<isFound<<endl;
	cin>>s;
	
	isFound = searchTrie(trie, s, s.length());
	cout<<s<<" --> "<<isFound<<endl;
	return 0;
}