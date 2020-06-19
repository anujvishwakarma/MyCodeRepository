#include <bits/stdc++.h>
using namespace std;

struct node {
	bool isNode;
	struct node *child[26];
};

struct node *getNode(){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->isNode = false;
	for(int i=0;i<26;i++){
		temp->child[i]=NULL;
	}
	return temp;
}

void insert(struct node *root, string s){
	int i,j,k;
	struct node *crawl = root;
	for(i=0;i<s.length();i++){
		int index = s[i]-'a';
		if(crawl->child[index]==NULL){
			crawl->child[index]=getNode();
		}
		crawl=crawl->child[index];
	}
	crawl->isNode=true;
}

bool search(struct node *root, string s){
	struct node *crawl = root;
	for(int i=0;i<s.length();i++){
		int index = s[i]-'a';
		if(crawl->child[index]==NULL){
			return false;
		}
		crawl=crawl->child[index];
	}
	return (crawl!=NULL && crawl->isNode);
}	

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	string s[1000];
	cin>>n;
	struct node *root = getNode();
	for(i=0;i<n;i++){
		cin>>s[i];
		insert(root,s[i]);
	}
	string a;
	cin>>a;
	bool isPresent = search(root,a);
	cout<<isPresent<<endl;
	return 0;
}
