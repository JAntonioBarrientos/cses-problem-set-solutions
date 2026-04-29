#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, w;
    cin >> n >> w;
    vector<ll> price(n+1);
    vector<ll> pages(n+1);
    for(int i = 1; i <= n; i++){
        cin >> price[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> pages[i];
    }
    vector<ll> dp(w+1, 0);
    for(int i = 1; i <= n; i++){
        for(int j = w; j >=0 ; j--){
            if(j - price[i] >= 0){
                dp[j] = max(dp[j], pages[i] + dp[j-price[i]]);
            }
        }
    }
    cout << dp[w] << "\n";
    return 0;
}
