#include <bits/stdc++.h>
using namespace std;

int getSum(int Bit[10],int index){
	int sum=0;
	index++;
	while(index>0){
      sum+=Bit[index];
      index-=index & (-index);
	}
 return sum;
}

void updateBit(int Bit[10],int index,int value,int n){
	index++;
	while(index<=n){
		Bit[index]+=value;
		index+=index & (-index);
	}
}

void construct(int a[10],int Bit[100],int n){
   for(int i=0;i<n;i++){
   	updateBit(Bit,i,a[i],n);
   }
}

int main(int argc, char const *argv[])
{
    int i,j,k,l,m,n,x,y;
    int a[10001]={0};
    int Bit[100001]={0};
    cin>>n;
    for(i=0;i<n;i++){
    	cin>>a[i];
    }
    construct(a,Bit,n);	
    for(i=0;i<=n;i++){
    	cout<<Bit[i]<<" ";
    }
    cout<<endl;
    cin>>x>>y;
    x-=1;
    y-=1;
     cout<<getSum(Bit,x)<<endl;
     cout<<getSum(Bit,y)<<endl;
    int ans=getSum(Bit,y)-getSum(Bit,x);
    cout<<ans<<endl;
	return 0;
}