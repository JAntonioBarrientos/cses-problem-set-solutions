#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    pair<int,int> start;
    pair<int,int> end;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for(int i = 0; i< n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++){
            if(s[j] == 'A'){
                start = {i, j};
            }
            if(s[j] == 'B'){
                end = {i, j};
            }
            if(s[j] == '#'){
                vis[i][j] = true;
            }
        }
    }
    vector<vector<pair<int,int>>> father(n, vector<pair<int,int>>(m));
    queue<pair<int,int>> q;
    q.push(start);
    vis[start.first][start.second] = true;

    vector<pair<int,int>> deltas = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    while(!q.empty()){
        auto [i,j] = q.front();
        q.pop();
        if(i == end.first and j == end.second){
            break;
        }
        for(auto [dx, dy]: deltas){
            int ni = i +dx;
            int nj = j + dy;
            if(0<= ni and ni < n and 0 <= nj and nj < m){
                if(!vis[ni][nj]){
                    vis[ni][nj] = true;
                    q.push({ni,nj});
                    father[ni][nj] = {i,j};
                }
            }
        }
    }

    if(!vis[end.first][end.second]){
        cout << "NO" << endl;
        return 0;
    }
    stack<char> path;
    int ci = end.first;
    int cj = end.second;
    while(start.first != ci or start.second != cj){
        auto &[fi,fj] = father[ci][cj];
        if(fi == ci){
            if(fj+1 == cj){
                path.push('R');
            }
            else{
                path.push('L');
            }
        }
        else if(fj == cj){
            if(fi +1 == ci){
                path.push('D');
            }
            else{
                path.push('U');
            }
        }
        ci = fi;
        cj = fj;
    }
    string ans;
    while(!path.empty()){
        ans += path.top();
        path.pop();
    }
    cout << "YES" << endl;
    cout << ans.size() << endl;
    cout << ans << endl;
    return 0;
}

