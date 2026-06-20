#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const vector<pair<int,int>> dir = {{1,0}, {-1,0}, {0, 1}, {0,-1}};

void dfs(vector<vector<bool>> &vis, int i, int j){
    for(auto [dx, dy]: dir){
        int ni = i + dx;
        int ny = j + dy;
        if(!vis[ni][ny]){
            vis[ni][ny] = true;
            dfs(vis, ni, ny);
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> vis(n+2, vector<bool>(m+2, true));
    string s;
    for(int i = 1; i <= n; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            if(s[j] == '.'){
                vis[i][j+1] = false;
            }
        }
    }
    int cnt = 0;
    for(int i = 1; i <=n; i++){
        for(int j = 1; j <= m; j++){
            if(!vis[i][j]){
                vis[i][j] = true;
                dfs(vis, i, j);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
