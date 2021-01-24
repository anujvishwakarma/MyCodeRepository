#include <bits/stdc++.h>
using namespace std;

void input(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}


std::vector<int> getNextGreater(std::vector<int> &data, int n){
	int i,j,k;
	i=n-1;
	while(i>0){
		if(data[i-1]<data[i]){
			break;
		}
		i--;
	}
	if(i==0){
		return data;
	}

	int number = data[i-1];
	int index = i;
	int smallest = i;
	for(i=index;i<n;i++){
		if(data[i]>number && data[i]<data[smallest]){
			smallest = i;
		}
	}
	swap(data[index-1], data[smallest]);
	sort(data.begin()+index, data.end());
	return data;
}

int main(int argc, char const *argv[]) {
	input();
	int i,j,k;
	int number;
	std::vector<int> data;
	cin>>number;
	while(number){
		k = number%10;
		number=number/10;
		data.push_back(k);
	}
	reverse(data.begin(), data.end());
	std::vector<int> greaterElement = getNextGreater(data, data.size());
	for(i=0;i<greaterElement.size();i++){
		cout<<greaterElement[i];
	}
	cout<<endl;
	return 0;
}