#include <iostream>
#include <algorithm>
using namespace std;

void print(pair<int,int>p[10],int n){
	int i;
   for(i=0;i<n;i++){
   	cout<<p[i].first<<" "<<p[i].second<<endl;
   }
}

bool go(pair<int,int>a,pair<int,int>b){
  return a.first<b.first;
}

/*bool rev(pair<int,int>a,pair<int,int>b){
 return a.second>b.second;
}*/

int main(int argc, char const *argv[])
{
	int i,j,k,l,m,n;
	pair<int,int>p[1000];
    cin>>n;
    for(i=0;i<n;i++){
    	cin>>p[i].first>>p[i].second;
    }
    sort(p,p+n,go);
    print(p,n);
   // sort(p,p+n,rev);
   // print(p,n);
	return 0;
}