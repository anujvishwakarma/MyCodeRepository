#include <bits/stdc++.h>
using namespace std;

void input(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

int getPrecedence(char c){
	if(c=='*' || c=='/'){
		return 2;
	}
	else if(c=='+' || c=='-'){
		return 1;
	}
	return -1;
}

string getPostfixExpression(string s){
	int i,j,k;
	string ans = "";
	stack<char> myStack;
	for(i=0;i<s.length();i++){
		if(s[i]>='a' && s[i]<='z'){
			ans+=s[i];
		}
		else if(myStack.empty() || s[i] == '('){
			myStack.push(s[i]);
		}
		else if(s[i]==')'){
			while(!myStack.empty() && myStack.top()!='('){
				ans+=myStack.top();
				myStack.pop();
			}
			if(!myStack.empty() && myStack.top()=='('){
				myStack.pop();
			}
		}else{
			while(!myStack.empty() && getPrecedence(myStack.top()) >= getPrecedence(s[i])){
				ans += myStack.top();
				myStack.pop();
			}
			myStack.push(s[i]);
		}
	}
	while(!myStack.empty()){
		ans+=myStack.top();
		myStack.pop();
	}
	return ans;
}

int main(int argc, char const *argv[]){
	int i,j,k,l,m,n;
	string s;
	cin>>s;
	string ans = getPostfixExpression(s);
	cout<<ans<<endl;
	return 0;
}
