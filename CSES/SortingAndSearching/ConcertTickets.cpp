#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int n, m, x;
  cin >> n >> m;
  multiset<int, greater<int>> h;
  while (n--) {
    cin >> x;
    h.insert(x);
  }
  while (m--) {
    cin >> x;
    auto it = h.lower_bound(x);
    if (it == h.end()) cout << "-1\n";
    else {
      cout << *it << endl;
      h.erase(it);
    }
  }
}

/*#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
	long long int i,j,k,l,m,n, index;
	cin>>n>>m;
	std::vector<long long int> tickets;
	std::vector<long long int> persons;
	for(i=0;i<n;i++){
		cin>>k;
		tickets.push_back(k);
	}
	for(i=0;i<m;i++){
		cin>>k;
		persons.push_back(k);
	}
	sort(tickets.begin(), tickets.end());
	std::vector<long long int> :: iterator position;

	for(i=0;i<m;i++){
		if(tickets.size()){
			position = lower_bound(tickets.begin(), tickets.end(), persons[i]);
			index = position - tickets.begin();
			if(index==0 && tickets[index] > persons[i]){
				cout<<"-1"<<endl;
				continue;
			}
			if(index==n || tickets[index]>persons[i]){
				index--;
			}
			cout<<tickets[index]<<endl;
			tickets.erase(tickets.begin() + index);
		}else{
			cout<<"-1"<<endl;
		}
	}
	return 0;
}*/