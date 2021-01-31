#include <bits/stdc++.h>
using namespace std;

void input(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

struct node {
	int data;
	struct node *next;
};

void printList(struct node *head){
	cout<<"Printing the list"<<endl;
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

struct node *insertNode(struct node *start, int value){
	int i,j;
	struct node *tmp = (struct node *)malloc(sizeof(struct node ));
	tmp->data=value;
	tmp->next=NULL;

	struct node *head = start;
	if(start==NULL){
		return tmp;
	}
	while(head->next!=NULL){
		head=head->next;
	}
	head->next=tmp;
	return start;
}

struct node *deleteNode(struct node *head, int value){
	if(head == NULL){
		return NULL;
	}
	struct node *tmp ;
	if(head->data == value){
		tmp=head;
		head = head->next;
		free(tmp);
		return head;
	}
	tmp=head;
	while(head->next!=NULL && head->next->data!=value){
		head=head->next;
	}
	head->next=head->next->next;
	return tmp;
}

struct node *swapTheNode(struct node *head, int a, int b){
	cout<<"Swapping the node "<<a<<" "<<b<<endl;
	int i,j,k;
	if(a==b){
		return head;
	}

	struct node *currX = head;
	struct node *currY = head;

	struct node *prevX = NULL;
	struct node *prevY = NULL;

	while(currX->data!=a){
		prevX = currX;
		currX = currX->next;
	}

	while(currY->data!=b){
		prevY=currY;
		currY=currY->next;
	}

	if(prevX != NULL){
		prevX->next= currY;
	}else{
		head = currX;
	}

	if(prevY !=NULL){
		prevY->next=currX;
	}else{
		head = prevY;
	}

	struct node *temp = currX->next;
	currX->next = currY->next;
	currY->next = temp;
	return head;
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	input();
	cin>>n;
	struct node *start = NULL;
	for(i=0;i<n;i++){
		cin>>k;
		start = insertNode(start, k);
	}
	//print_the_list
	printList(start);
	

	/****************Delete the node******************/
	//delete the node - 
	//start = deleteNode(start, 4);
	//printList(start);
	/*************************************************/


	/**************Swap the Node**********************/
	//	
	cin>>n>>m;
	start = swapTheNode(start, n , m);
	printList(start);
	/*************************************************/

	return 0;
}