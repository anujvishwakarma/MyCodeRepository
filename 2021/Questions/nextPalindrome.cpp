#include <bits/stdc++.h>
using namespace std;

void input(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

vector<int> getNextPalindrome(std::vector<int> &data, int n, bool all9){
	int i,j,k,l,m;
	if(all9){
		std::vector<int> temp;
		temp.push_back(1);
		for(i=0;i<n-1;i++){
			temp.push_back(0);
		}
		temp.push_back(1);
		return temp;
	}


	int left, right;
	int mid = n/2;
	left = mid-1;
	bool isleftSmall = false;


	if(n%2==0){
		right = mid;
	}else{
		right=mid+1;
	}

	while(left>=0 && data[left]==data[right]){
		left--;right++;
	}
	if(left<0 || data[left] == data[right]){
		isleftSmall = true;
	}

	while(left>=0){
		data[right]=data[left];
		right++;
		left--;
	}

	if(isleftSmall){
		int carry = 1;
		int iter1 = mid-1;
		int iter2;
		if(n%2 == 1){
			data[mid]+=carry;
			carry = data[mid]/10;
			data[mid]%=10;
			iter2=mid+1;
		}else{
			iter2=mid;
		}
		while(iter1>=0){
			data[iter1]+=carry;
			carry = data[iter1]/10;
			data[iter1]%=10;
			data[iter2] = data[iter1];
			iter2++;
			iter1--;
		}
	}
	return data;
}

int main(int argc, char const *argv[]){
	input();
	int i,j,k;
	int number;
	std::vector<int> data;
	bool all9 = true;
	cin>>number;
	while(number){
		k = number%10;
		number=number/10;
		data.push_back(k);
		if(k!=9){
			all9 = false;
		}
	}
	reverse(data.begin(), data.end());
	std::vector<int> palin = getNextPalindrome(data, data.size(), all9);
	for(i=0;i<palin.size();i++){
		cout<<palin[i];
	}
	cout<<endl;
	return 0;
}