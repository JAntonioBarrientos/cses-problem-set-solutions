#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int grid_size = 7;
bool visited[grid_size+2][grid_size+2] = {false};
ll ans = 0;
string s = "";
const vector<pair<int,int>> dir = {{-1,0}, {1, 0}, {0, 1}, {0,-1}};

void dfs(int i, int j, int depth){
    if(depth == 48 and j == 1 and i == grid_size){
        ans++;
        return;
    }
    if(j == 1 and i == grid_size){
        return;
    }
    if(visited[i+1][j] == visited[i-1][j] and visited[i][j+1] == visited[i][j-1]){
        if(visited[i+1][j] != visited[i][j+1]){
            return;
        }
    }
    if(s[depth] == 'L'){
        if(!visited[i][j-1]){
            visited[i][j-1] = true;
            dfs(i, j-1, depth+1);
            visited[i][j-1] = false;
        }
    }
    else if(s[depth] == 'R'){
        if(!visited[i][j+1]){
            visited[i][j+1] = true;
            dfs(i, j+1, depth+1);
            visited[i][j+1] = false;
        }
    }
    else if(s[depth] == 'U'){
        if(!visited[i-1][j]){
            visited[i-1][j] = true;
            dfs(i-1, j, depth+1);
            visited[i-1][j] = false;
        }
    }
    else if(s[depth] == 'D'){
        if(!visited[i+1][j]){
            visited[i+1][j] = true;
            dfs(i+1,j, depth+1);
            visited[i+1][j] = false;
        }
    }
    else{
        for(auto [x, y]: dir){
            if(!visited[i+x][j+y]){
                visited[i+x][j+y] = true;
                dfs(i+x,j+y, depth+1);
                visited[i+x][j+y] = false;
            }
        }
    }
    return; 
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    for(int i = 0; i< grid_size+2; i++){
        visited[0][i] = true;
        visited[i][0] = true;
        visited[grid_size+1][i] = true;
        visited[i][grid_size+1] = true;
    }
    visited[1][1] = true;
    dfs(1,1, 0);
    cout << ans << endl;
    return 0;
}
