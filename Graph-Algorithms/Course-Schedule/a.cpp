#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> in_d(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        in_d[b-1]++;
    }
    queue<int> q;
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(in_d[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        ans.push_back(curr);
        for(auto nei: adj[curr]){
            in_d[nei]--;
            if(in_d[nei] == 0){
                q.push(nei);
            }
        }
    }
    if(ans.size() != n){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for(int i = 0; i < n; i++){
        cout << ans[i]+1 << " ";
    }
    cout << endl;
    return 0;
}
