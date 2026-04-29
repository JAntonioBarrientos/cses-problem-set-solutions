#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a+1, vector<int>(b+1, 1e9));
    int m = min(a,b);
    for(int i = 0; i <= m; i++){
        dp[i][i] = 0;
    }
    for(int i = 0; i<=a; i++){
        dp[i][0] = 0;
    }
    for(int i = 0; i <= b; i++){
        dp[0][b]= 0;
    }
    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= b; j++){
            //cortes horizontales
            for(int k = 1; k <= i-1; k++){
                dp[i][j] = min(dp[i][j], 1+ dp[k][j] + dp[i-k][j]);
            }
            for(int k = 1; k <= j-1; k++){
                dp[i][j] = min(dp[i][j], 1+ dp[i][k] + dp[i][j-k]);
            }
        }
    }
    cout << dp[a][b] << endl;
   
    return 0;
}
