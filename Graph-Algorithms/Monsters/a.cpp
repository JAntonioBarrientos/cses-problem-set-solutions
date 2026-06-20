#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    pair<int,int> me;
    vector<pair<int,int>> monsters;
    vector<vector<bool>> vis_mons(n, vector<bool>(m, false));
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++){
            if(s[j] == 'M'){
                monsters.emplace_back(i,j);
            }
            else if(s[j] == 'A'){
                me = {i, j};
            }
            else if(s[j] == '#'){
                vis_mons[i][j] = true;
                vis[i][j] = true;
            }
        }
    }

    int inf = 1e8;
    vector<vector<int>> dist_mons(n, vector<int>(m, inf));
    vector<vector<int>> dist(n, vector<int>(m, inf));

    // Multi source bfs for the monsters;
    queue<pair<int,int>> q;
    for(auto m: monsters){
        q.push(m);
        vis_mons[m.first][m.second] = true;
        dist_mons[m.first][m.second]= 0;
    }
    vector<pair<int,int>> deltas = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    while(!q.empty()){
        auto &[i,j] = q.front();
        q.pop();
        for(auto &[dx, dy]: deltas){
            int ni = dx+i;
            int nj = dy+j;
            if(0 <= ni and ni < n and 0 <= nj and nj < m){
                if(!vis_mons[ni][nj]){
                    vis_mons[ni][nj] = true;
                    dist_mons[ni][nj] = 1 + dist_mons[i][j];
                    q.push({ni, nj});
                }
            }
        }
    }

    q.push(me);
    vis[me.first][me.second] = true;
    dist[me.first][me.second] = 0;
    while(!q.empty()){
        auto &[i,j] = q.front();
        q.pop();
        for(auto &[dx,dy]: deltas){
            int ni = i +dx;
            int nj = j + dy;
            if(0<= ni and ni < n and 0 <= nj and nj < m){
                if(!vis[ni][nj]){
                    vis[ni][nj] = true;
                    dist[ni][nj] = 1 + dist[i][j];
                    q.push({ni,nj});
                }
            }
        }
    }

    vector<vector<bool>> is_safe(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(dist[i][j] < dist_mons[i][j]){
                is_safe[i][j] = true;
            }
        }
    }

    q.push(me);
    is_safe[me.first][me.second] = false;
    bool escape = false;
    pair<int,int> exit = {-1,-1};
    vector<vector<pair<int,int>>> father(n, vector<pair<int,int>>(m, {-1,-1}));
    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();
        if(i == 0 or i == n-1 or j == 0 or j== m-1){
            escape = true;
            exit = {i, j};
            break;
        }
        for(auto [dx,dy]: deltas){
            int ni = i + dx;
            int nj = j + dy;
            if(0 <= ni and ni < n and 0 <= nj and nj < m){
                if(is_safe[ni][nj]){
                    is_safe[ni][nj] = false;
                    father[ni][nj] = {i,j};
                    q.push({ni, nj});
                }
            }
        }
    }
    if(!escape){
        cout << "NO\n";
        return 0;
    }
    vector<char> path;
    pair<int,int> curr = exit;
    while(curr != me){
        auto &[fi, fj] = father[curr.first][curr.second];
        auto &[ci, cj] = curr;
        if(fi == ci){
            if(fj -1 == cj){
                path.push_back('L');
            }
            else{
                path.push_back('R');
            }
        }
        else if( fj == cj){
            if(fi -1 == ci){
                path.push_back('U');
            }
            else{
                path.push_back('D');
            }
        }
        curr = father[ci][cj];
    }

    cout << "YES\n";
    cout << path.size() << endl;
    reverse(path.begin(), path.end());
    for(auto c: path){
        cout << c;
    }
    cout << endl;

    return 0;
}
