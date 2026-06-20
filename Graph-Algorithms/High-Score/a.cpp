#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(int node, const vector<vector<pair<int,ll>>> &adj, vector<bool> &vis, vector<tuple<int,int,ll>> &edges){
    vis[node] = true;
    for(auto [nei, w]: adj[node]){
        edges.emplace_back(node, nei, w);
        if(!vis[nei]){
            dfs(nei, adj, vis, edges);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<tuple<int,int,ll>> edges;
    vector<vector<pair<int,ll>>> adj(n);
    for(int i = 0; i <m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u-1].emplace_back(v-1, w);
    }
    vector<bool> vis(n);
    dfs(0, adj, vis,edges);
    ll inf = 1e18;
    vector<ll> distance(n, -inf);
    distance[0] = 0;
    for(int i = 0; i < n; i++){
        for(auto &[u, v, w]: edges){
            distance[v] = max(distance[v], distance[u] + w);
        }
    }
    for(auto &[u, v, w]: edges){
        if(distance[v] < distance[u] + w){
            distance[n-1] = -1;
            break;
        }
    }
    cout << distance[n-1] << endl;
    return 0;
}
