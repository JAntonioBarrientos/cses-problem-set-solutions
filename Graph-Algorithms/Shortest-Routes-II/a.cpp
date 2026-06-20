#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    ll inf = 1e18;
    vector<vector<ll>> matrix(n, vector<ll>(n, inf));
    for(int i = 0; i < n; i++){
        matrix[i][i] = 0;
    }

   for(int i = 0; i<m; i++){
        ll a, b, w;
        cin >> a >> b >> w;
        matrix[a-1][b-1] = min(matrix[a-1][b-1], w);
        matrix[b-1][a-1] = min(matrix[a-1][b-1], w);
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    while(q--){
        int u, v;
        cin >> u  >> v;
        if(matrix[u-1][v-1] == inf){
            cout << -1 << "\n";
        }
        else{
        cout << matrix[u-1][v-1] << "\n";
        }
    }
    return 0;
}
