#include <bits/stdc++.h>
using namespace std;


vector<int> tree[200001];
long long int subtreeAns[200001];
long long int ans[200001];
int subtreeSize[200001];
 
void preprocessing(int src, int par)
{
    int numOfNodes = 1;
    long long int ansForSubtree = 0;
    for(int child : tree[src])
    {
        if(child != par)
        {
            preprocessing(child, src);
            numOfNodes += subtreeSize[child];
            ansForSubtree += subtreeSize[child] + subtreeAns[child];
        }
    }
    subtreeSize[src] = numOfNodes;
    subtreeAns[src] = ansForSubtree;
}
 
 
 
void solve(int src, int par, long long int par_ans, long long int& totalNodes) {
    ans[src] = subtreeAns[src] + (par_ans + (totalNodes - subtreeSize[src]));
 
    for(int child : tree[src])
    {
        if(child != par)
            solve(child, src, ans[src] - (subtreeAns[child] + subtreeSize[child]), totalNodes);
    }
}
 
int main() {
        long long int t,n,m,x,i,j,k,q;
        cin >> n;
        for(i=0;i<n-1;i++)
        {
            int u,v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        preprocessing(1, 0);
        solve(1, 0, 0, n);
        for(i=1;i<n+1;i++){
            cout << ans[i] <<' ';
        }

   return 0;
}