#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,ll>>> adj(n+1);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    vector<bool> processed(n+1);
    ll inf = 1e18;
    vector<ll> distance(n+1, inf);
    distance[1] = 0;
    priority_queue<pair<ll,int>> q;
    q.push({0, 1});
    while(!q.empty()){
        auto a = q.top().second;
        q.pop();
        if(processed[a])
            continue;
        processed[a] = true;
        for(auto [b, w]: adj[a]){
            if(distance[b] > distance[a] + w){
                distance[b] = distance[a] + w;
                q.push({-distance[b], b});
            }
        }
    }
    for(int i = 1; i <=n; i++){
        cout << distance[i] << " ";
    }
    cout << endl;
    return 0;
}
