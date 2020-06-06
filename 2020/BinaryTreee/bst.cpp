#include <bits/stdc++.h>
using namespace std;
/*
7
4 3 8 1 2 5 7
 */

struct node {
    int data;
    struct node *left;
    struct node *right;
};

void preOrderTree(struct node *root){
	if(root==NULL){
		return;
	}
	preOrderTree(root->left);
	cout<<root->data<<" ";
	preOrderTree(root->right);
}

struct node *insertNode(struct node *root, int value){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	if(root==NULL){
		temp->data=value;
		temp->left=NULL;
		temp->right=NULL;
		return temp;
	}
	if(value > root->data){
		root->right=insertNode(root->right,value);
	}else{
		root->left=insertNode(root->left,value);
	}
	return root;
}

void getPreAndSucc(struct node *root,struct node *&pred,
	struct node *&succ, int key){
	if(root==NULL){return;}

	if(root->data == key){
		if(root->left!=NULL){
			struct node *temp = root->left;
			while(temp->right!=NULL){
				temp=temp->right;
			}
			pred=temp;
		}
		if(root->right!=NULL){
			struct node *temp = root->right;
			while(temp->left!=NULL){
				temp=temp->left;
			}
			succ=temp;
		}
		return;
	}
	if(root->data < key){
		pred = root;
		getPreAndSucc(root->right, pred, succ, key);
	}
	else{
		succ = root;
		getPreAndSucc(root->left, pred, succ, key);
	}
}

void getPreAndSucc(struct node *root,int k){
	struct node *pred=NULL, *succ=NULL;
	getPreAndSucc(root, pred, succ, k);
	cout<<"Predecessor is "<<pred->data<<" and Successor is "<<succ->data<<" "<<endl;
}

bool isBST(struct node *root,struct node *&prev){
	if(root==NULL){return true;}
	if(!isBST(root->left,prev)){
		return false;
	}
	//Allowed distinct values.
	if(prev!=NULL && prev->data >= root->data){
		return false;
	}
	prev=root;
	return isBST(root->right, prev);
}

bool printAncestors(struct node *root, int k){
	if(root==NULL){return false;}

	if(root->data==k){return true;}

	if( printAncestors(root->left,k) || printAncestors(root->right, k)){
		cout<<root->data<<" ";
		return true;
	}
	return false;
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	cin>>n;
	struct node *root=NULL;
	for(i=0;i<n;i++){
		cin>>k;
		root=insertNode(root,k);
	}
	preOrderTree(root);cout<<endl;
	
	//Get Predecessor and Successor;
	/*cin>>k;
	getPreAndSucc(root,k);
	*/

	//printAncestors(root,5);cout<<endl;
	
	/*
	struct node *prev;
	cout<<isBST(root, prev)<<endl;
	*/

	return 0;
}
