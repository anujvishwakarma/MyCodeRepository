#include <bits/stdc++.h>
using namespace std;

void input(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct node *insert(struct node *root, int data){
	int i,j;
	struct node *tmp;
	if(root == NULL){
		tmp = (struct node *)malloc(sizeof(struct node));
		tmp->data = data;
		tmp->left = NULL;
		tmp->right = NULL;
		return tmp;
	}
	else if(root->data < data){
		root->right = insert(root->right, data); 
	}
	else{
		root->left = insert(root->left, data);
	}
	return root;
}

void inorder(struct node *root){
	if(root == NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main(int argc, char const *argv[]) {
	input();
	int i,j,k,m,n;
	cin>>n;
	struct node *root = NULL;
	for(i=0;i<n;i++){
		cin>>k;
		root=insert(root,k);
	}
	//print the in-order of tree;
	inorder(root);
	return 0;
}