#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	long long int i,j,k,l,m,n, ans =0, curr_ans =0;
	pair<long long int, long long int> maxPair;
	multiset<long long int> segments;
	cin>>n>>m;
	set<long long int> lineNumber;
	lineNumber.insert(0);
	lineNumber.insert(n);
	segments.insert(n);
	for(i=0;i<m;i++){
		cin>>k;
		auto it = lineNumber.upper_bound(k);
		long long int right = *it;
		long long int left = *prev(it);

		// removing old segments if current value falls under it.
		segments.erase(segments.find(right - left));
		segments.insert(right - k);
		segments.insert(k - left);

		lineNumber.insert(it, k);
		cout<<*(segments.rbegin())<<" ";

	}
	return 0;
}