#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	struct node *next;
};

int findLength(struct node *head){
	int count=0;
	while(head){
		head=head->next;
		count++;
	}
	cout<<"length is "<<count<<endl;
	return count;
}

struct node *insertData(int value, struct node *head){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data=value;
	temp->next=NULL;
	if(head==NULL){
		return temp;
	}
	struct node *runner = head;
	while(runner->next!=NULL){
		runner=runner->next;
	}
	runner->next=temp;
	return head;
}

void printList(struct node *head){
	cout<<"The list is"<<endl;
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<"---------"<<endl;
	cout<<endl;
}

struct node *swapNodes(struct node *head, int x, int y){
	if(x==y){return head;}

	struct node *prevX=NULL, *prevY=NULL, *currX=NULL, *currY=NULL;
	currX=head;
	while(currX && currX->data!=x){
		prevX=currX;
		currX=currX->next;
	}
	currY=head;
	while(currY && currY->data!=y){
		prevY=currY;
		currY=currY->next;
	}
	if(prevX!=NULL){
		prevX->next=currY;
	}else{
		head = currY;
	}
	if(prevY!=NULL){
		prevY->next=currX;
	}else{
		head = currX;
	}
	cout<<currY->data<<" "<<currX->data<<endl;
	struct node *temp = currY->next;
	currY->next=currX->next;
	currX->next=temp;
	return head;
}

void swapData(struct node *head){
	int x,y;
	cin>>x>>y;
	struct node *start = swapNodes(head,x,y);
	printList(start);
}

struct node *reverseList(struct node *head){
	struct node *prev,*curr,*nextNode;
	prev=NULL;
	nextNode=NULL;
	curr=head;
	while(curr!=NULL){
		nextNode=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nextNode;
	}
	return prev;
}

void reverse(struct node *head){
	struct node *start = reverseList(head);
	printList(start);
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	cin>>n;
	struct node *start=NULL;
	for(i=0;i<n;i++){
		cin>>k;
		start=insertData(k,start);
	}
	printList(start);
	//findLength(start);
	//swapData(start);
	//reverse(start);

	return 0;
}