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

struct node *addNumbers(struct node *a, struct node *b, int n, int m){
	struct node *result = NULL;
	struct node *running = NULL;
	int carry = 0;
	int data = 0;
	while(a!=NULL || b!=NULL){	
		data = 0;
		if(a){
			data+=a->data;
		}
		if(b){
			data+=b->data;
		}
		if(carry){
			data+=carry;
		}
		carry = data/10;
		data = data%10;

		cout<<data<<" "<<carry<<endl;

		struct node *temp = (struct node *)malloc(sizeof(struct node ));
		temp->data = data;
		temp->next = NULL;
		if(result == NULL){
			result = temp;
			running = result;
		}
		else{
			running->next = temp;
			running = running->next;
		}
		if(a){
			a=a->next;
		}
		if(b){
			b=b->next;
		}
	}
	if(carry > 0){
		struct node *temp = (struct node *)malloc(sizeof(struct node ));
		temp->data = carry;
		temp->next = NULL;
		running->next = temp;
	}
	return result;
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	input();
	cin>>n>>m;
	struct node *start1 = NULL;
	struct node *start2 = NULL;
	for(i=0;i<n;i++){
		cin>>k;
		start1 = insertNode(start1, k);
	}
	for(i=0;i<m;i++){
		cin>>k;
		start2 = insertNode(start2, k);
	}
	//print_the_list
	printList(start1);
	printList(start2);

	struct node *result = addNumbers(start1, start2, n, m);
	cout<<"Additing 2 numbers"<<endl;
	printList(result);

}