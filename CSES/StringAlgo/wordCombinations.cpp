#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
long long int ans=0;
#define mod (long long int)1e9+7

struct node *globalRoot;

struct node	{
	char value;
	vector<struct node *>child;
};

struct node *getNode(char key){
	struct node *temp = new node;
	temp->value = key;
	temp->child = {};
	return temp;
}

int isPresent(struct node *root, char value){
	for(int i=0;i<root->child.size(); i++){
		if(((root)->child[i])->value == value){
			return i;
		}
	}
	return -1;
}

void insertString(string s, struct node *root){
	if(s.size()==0){
		(root->child).insert((root->child).begin(), getNode('*'));
	}
	int position = isPresent(root, s[0]);
	if(position == -1){
		struct node *temp = root;
		for(int i=0;i<s.size();i++){
			temp->child.push_back(getNode(s[i]));
			temp = *((temp)->child.end()-1);
		}
		temp->child.insert(temp->child.begin(), getNode('*'));
		return;
	}else{
		s.erase(s.begin());
		insertString(s, root->child[position]);
	}
}

void calculateAns(string data, struct node *root){
	if(data.size()==0 && root->child[0]->value=='*'){
		ans++;
	}
	else{
		if(root->child[0]->value == '*'){
			calculateAns(data, globalRoot);
		}
		int position = isPresent(root, data[0]);
		data.erase(data.begin());
		if(position!=-1){
			calculateAns(data, root->child[position]);
		}
	}
}

int main(int argc, char const *argv[]){
	ll i,j,k,l,m,n;
	string data, s;
	cin>>data;
	cin>>n;
	struct node *root=getNode('*');
	for(i=0;i<n;i++){
		cin>>s;
		insertString(s, root);
	}
	globalRoot = root;
	calculateAns(data, root);
	cout<<ans<<endl;
	return 0;
}