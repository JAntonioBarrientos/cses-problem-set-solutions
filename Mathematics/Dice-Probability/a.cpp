#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    int maxSum = 6*n +1;
    vector<vector<ld>> dp(n+1, vector<ld>(maxSum, 0));
 
    dp[0][0] = 1;
    for(int i = 1; i <=n; i++){
        for(int j = 0; j < maxSum; j++){
            ld cur = dp[i-1][j];
            if(cur>0){
                for(int k = 1; k <= 6; k++){
                    dp[i][j+k] += cur/6;
                }
            }
        }
    }
 
    ld ans = 0;
    for(int i = a; i <=b; i++){
        ans += dp[n][i];
    }
    cout << setprecision(6) << fixed;
    cout << ans << endl;
    return 0;
}
