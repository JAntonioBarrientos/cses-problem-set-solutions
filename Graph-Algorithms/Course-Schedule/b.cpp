#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(int node, const vector<vector<int>> &adj, vector<int> &color, vector<int> &ans, bool &cycle){
    if(cycle){
        return;
    }
    color[node] = 1;
    for(auto nei: adj[node]){
        if(color[nei] == 0){
            dfs(nei, adj, color, ans, cycle);
        }
        if(color[nei] == 1){
            cycle = true;
            return;
        }
        if(cycle){
            return;
        }
    }
    color[node] = 2;
    ans.push_back(node);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
    }
    vector<int> color(n);
    vector<int> ans;
    bool cycle = false;
    for(int i = 0; i < n; i++){
        if(color[i] == 0){
            dfs(i, adj, color, ans, cycle);
            if(cycle){
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < n; i++){
        cout << ans[i] +1 << " ";
    }

    return 0;
}


