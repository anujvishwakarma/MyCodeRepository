#include <bits/stdc++.h>
using namespace std;

/* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 */

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

void levelOrder(struct node *root){
	int i;
	queue<struct node *> myQueue;
	myQueue.push(root);
	while(!myQueue.empty()){
		struct node *curr = myQueue.front();
		myQueue.pop();
		cout<<curr->data<<" ";
		if(curr->left){
			myQueue.push(curr->left);
		}
		if(curr->right){
			myQueue.push(curr->right);
		}
	}
}

void inorderbyStack(struct node *curr){
	stack<struct node *> myStack;

	while(curr!= NULL || !myStack.empty()){
		while(curr!= NULL){
			myStack.push(curr);
			curr = curr->left;
		}
		curr = myStack.top();
		myStack.pop();
		cout<<curr->data<<" ";
		curr = curr->right;
	}
}

int height(struct node *root){
	if(root == NULL){
		return 0;
	}
	int lefth = height(root->left);
	int righth = height(root->right);

	return 1+max(lefth, righth);
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
	cout<<"-----------Inorder-------->"<<endl;
	inorder(root);
	cout<<endl;
	cout<<"-------------------------->"<<endl;

	//levelOrder;
	//levelOrder(root);

	//int h = height(root);
	//cout<<"height is "<<h<<endl;
	//
	inorderbyStack(root);
	return 0;
}