#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(int node, const vector<vector<int>> &adj, vector<bool> &vis){
    vis[node] = true;
    for(auto nei: adj[node]){
        if(!vis[nei]){
            dfs(nei, adj, vis);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m ; i++){
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    vector<bool> vis(n,false);
    vector<int> cc;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i, adj, vis);
            cc.push_back(i);
        }
    }
    cout << cc.size()-1 << endl;
    for(int i = 1; i < cc.size(); i++){
        cout << cc[0]+1 << " " << cc[i]+1 << "\n";
    }
    return 0;
}
