#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *insert(struct node *root, int key){
	if(root==NULL){
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		temp->data=key;
		temp->left=NULL;
		temp->right=NULL;
		return temp;
	}
	if(key>root->data){
		root->right=insert(root->right,key);
	}
	if(key<root->data){
		root->left=insert(root->left,key);
	}
	return root;
}

void printInorderTree(struct node *root){
	if(root==NULL)return;
	printInorderTree(root->left);
	cout<<root->data<<" ";
	printInorderTree(root->right);
}

void printNodeAtdown(struct node *root, int key){
	if(root==NULL || key<0){
		return;
	}
	if(key==0){
		cout<<root->data<<" ";return;
	}
    printNodeAtdown(root->left,key-1);
    printNodeAtdown(root->right,key-1);
}

int printAtkDistance(struct node *root, int distance, int value){
	if(root==NULL){return -1;}

	if(root->data==value){
		printNodeAtdown(root,distance);
		return 0;
	}
	int dl=printAtkDistance(root->left, distance, value);
	if(dl!=-1){
		if(dl+1==distance){
			cout<<root->data<<" ";
		}else{
			printNodeAtdown(root->right,distance-dl-2);
		}
		return 1+dl;
	}
	int dr=printAtkDistance(root->right,distance, value);
	if(dr!=-1){
		if(dr+1==distance){
			cout<<root->data<<" ";
		}else{
			printNodeAtdown(root->left,distance-dr-2);
		}
		return 1+dr;
	}

	return -1;
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n,distance;
	cin>>n;
	struct node *root=NULL;
	for(i=0;i<n;i++){
		cin>>k;
		root=insert(root,k);
	}
	printInorderTree(root);
	cin>>distance>>m;
	printAtkDistance(root,distance,m);
	return 0;
}