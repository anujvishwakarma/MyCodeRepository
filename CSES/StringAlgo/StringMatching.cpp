#include <bits/stdc++.h>
using namespace std;

vector<int>zArray;

void fillZArray(string data){
	int i,n = data.length();
	int left, right, inBetween;
	left=right=0, zArray.assign(data.length(),0);
	for(i=1;i<n;i++){
		if(i>right){
			left=right=i;
			while(right<n && data[right - left] == data[right]){
				right++;
			}
			zArray[i]=right-left;
			right--;

		} else{
			inBetween = i-left;
			if(zArray[inBetween] < right - i + 1){
				zArray[i]=zArray[inBetween];
			}else{
				left = i;
				while(right<n && data[right - left] == data[right]){
					right++;
				}
				zArray[i]=right-left;
				right--;
			}
		}
	}
}

int main(int argc, char const *argv[]){
	long long int i,j,k,l,m,n,ans =0;
	string text, pattern;
	cin>>text>>pattern;

	string newData = pattern+"$"+text;
	fillZArray(newData);
	for(i=0;i<newData.length();i++){
		if(zArray[i]==pattern.length()){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
