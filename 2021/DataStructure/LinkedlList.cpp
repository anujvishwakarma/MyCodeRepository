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

	//delete the node - 
	start = deleteNode(start, 4);
	printList(start);

	return 0;
}