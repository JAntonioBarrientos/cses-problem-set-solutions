#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    vector<int> father(n+1);
    vector<int> distance(n+1, 1e7);
    queue<int> q;
    q.push(1);
    vis[1] = true;
    distance[1] = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if(curr == n){
            break;
        }
        for(auto nei: adj[curr]){
            if(!vis[nei]){
                vis[nei] = true;
                q.push(nei);
                father[nei] = curr;
                distance[nei] = distance[curr]+1;
            }
        }
    }

    if(!vis[n]){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << distance[n]+1 << "\n";
    int curr = n;
    vector<int> path;
    while(curr != 1){
        path.push_back(curr);
        curr = father[curr];
    }
    path.push_back(1);
    for(int i = path.size()-1; i >=0 ; i--){
        cout << path[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
