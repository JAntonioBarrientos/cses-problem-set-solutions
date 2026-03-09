#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e10;

vector<pair<int,int>> valid_moves(int i, int j, int n){
    vector<pair<int, int>> valid;
    vector<pair<int,int>> dirs{{1,2}, {2, 1}, {-1, -2}, {-2, -1}, {-1, 2}, {-2, 1}, {1, -2}, {2, -1}};
    for(auto &[dx, dy]: dirs){
        int new_i = i + dx;
        int new_j = j + dy;
        if( 0 <= new_i and new_i < n and 0 <= new_j and new_j < n){
            valid.push_back({new_i, new_j});
        }
    }
    return valid;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    vector<vector<ll>> moves(n, vector(n, inf));
    moves[0][0] = 0;

    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        pair<int, int> curr= q.front();
        q.pop();
        vector<pair<int,int>> valid = valid_moves(curr.first, curr.second, n);
        for(auto p: valid){
            if(moves[p.first][p.second] > moves[curr.first][curr.second]+1){
                moves[p.first][p.second] = moves[curr.first][curr.second]+1;
                q.push(p);
            }
        }
    }

    for(int i = 0; i< n; i++){
        for(int j = 0; j < n; j++){
            cout << moves[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
