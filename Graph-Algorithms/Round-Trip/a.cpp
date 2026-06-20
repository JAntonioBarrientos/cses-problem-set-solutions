#include <bits/stdc++.h>
using namespace std;

void dfs(int node, const vector<vector<int>> &adj, vector<bool> & vis, vector<int> &fatherof, int &start, int &end){
    if(start != -1){
        return;
    }
    vis[node] = true;
    for(auto nei: adj[node]){
        if(!vis[nei]){
            fatherof[nei] = node;
            dfs(nei, adj, vis, fatherof, start, end);
            if(start != -1) return;
        }
        else if(nei != fatherof[node]){
            start = node;
            end = nei;
            return;
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<bool> vis(n+1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> fatherof(n+1);
    vector<int> cycle;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            int start = -1;
            int end = -1;
            dfs(i, adj, vis, fatherof, start, end);
            if(start != -1){
                cycle.push_back(end);
                for(int curr = start; curr != end; curr = fatherof[curr]){
                    cycle.push_back(curr);
                }
                cycle.push_back(end);
                int cys = cycle.size();
                cout << cys << endl;
                for(int j = 0; j < cys; j++){
                    cout << cycle[j] << " ";
                }
                cout << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;

}



