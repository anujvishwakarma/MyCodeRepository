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

int getLength(struct node *start){
	int k=0;
	while(start!=NULL){
		k++;
		start = start->next;
	}
	return k;
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

struct node *loopThirdNode(struct node *start){
	struct node *run = start;
	while(run->next!=NULL){
		run = run -> next;
	}
	run->next = start->next->next;
	return start;
}

void removeLoop(struct node *start, struct node *loopNode){
	int i,j;
	struct node *slow = start;
    if(slow == loopNode){
	  while(loopNode->next != slow){
	 		loopNode=loopNode->next;
	  }
	  loopNode->next=NULL;
	  return;
	}
	while(slow->next != loopNode->next){
	 	slow = slow->next;
	 	loopNode = loopNode->next;
	}
	loopNode->next = NULL;
	return;
}

struct node *detectAndRemoveLoop(struct node *start){
	struct node *slow = start->next;
	struct node *fast = start->next->next;
	
	while(slow && fast && fast->next){
		if(slow == fast){
			removeLoop(start, fast);
			return start;
		}
		slow = slow->next;
		fast = fast->next->next;
	}
	return start;
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

	//this function creates loop
	start = loopThirdNode(start);
	start = detectAndRemoveLoop(start);
	printList(start);
}