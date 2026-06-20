#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool bfs(int start, const vector<vector<int>> &adj, vector<int> &color){
    queue<int> q;
    q.push(start);
    color[start] = 1;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto nei: adj[curr]){
            if(color[nei] == 0){
                color[nei] = color[curr] == 1? 2: 1;
                q.push(nei);
            }
            else if(color[nei] == color[curr]){
                cout << "IMPOSSIBLE\n";
                return false;
            }
        }
    }
    return true;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<int> vis(n+1);
    vector<int> color(n+1, 0);
    for(int i = 0;i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        if(color[i] == 0){
            if(!bfs(i, adj, color)){
                return 0;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << color[i] << " ";
    }
    cout << "\n";
   
    return 0;
}
