#include <bits/stdc++.h>
using namespace std;

#define inf INT_MAX

int printData(std::vector<string> data, std::vector<int> parent, int n){
    int currValue;
    if(parent[n]==1){
        currValue = 1;
    }else{
        currValue = 1 + printData(data,parent, parent[n] - 1);
    }
    cout<<endl;
    int start = parent[n]-1;
    int end = n-1;
    for(int i=start;i<=end;i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
}

void printWord(std::vector<string> data, int n, int line){
    int i,j,k,l;
    std::vector<std::vector<int> > extraSpace(n+1, std::vector<int> (n+1));
    std::vector<std::vector<int> > lineCost(n+1, std::vector<int> (n+1));
    std::vector<int> totalCost(n+1,0);
    std::vector<int> parent(n+1,0);

    for(i=1;i<=n;i++){
        extraSpace[i][i]= line - data[i-1].length();
        for(j=i+1;j<=n;j++){
            extraSpace[i][j] = extraSpace[i][j-1] - data[j-1].length() - 1;
        }
    }

    for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){
            if(extraSpace[i][j]<0){
                lineCost[i][j] = inf;
            }else if(j==n && extraSpace[i][j]>=0){
                lineCost[i][j]=0;
            }else{
                lineCost[i][j]= extraSpace[i][j] * extraSpace[i][j];
            }
        }
    }

    totalCost[0]=0;
    for(j=1;j<=n;j++){
        totalCost[j]=inf;
        for(i=1;i<=j;i++){
            if(totalCost[i-1]!=inf && lineCost[i][j]!=inf && 
                totalCost[j] > totalCost[i-1] + lineCost[i][j]){
                totalCost[j] = totalCost[i-1] + lineCost[i][j];
                parent[j]=i;
            }
        }
    }
    int cost = 0;
    for(i=0;i<=n;i++){
        cost+=totalCost[i];
    }
    cout<<"Total Cost is "<<cost<<endl;
    printData(data, parent, n);
}

int main(int argc, char const *argv[]){
    int i,j,k,l,m,n,line;
    cin>>n>>line;
    std::vector<string> statement;
    string s;
    for(i=0;i<n;i++){
        cin>>s;
        statement.push_back(s);
    }
    printWord(statement, n, line);
    return 0;
}