#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    // We sum the ones
    ll ans = 1*n;
    for(ll i = 2; i*i <= m; i++){
        ll div_floor = (n-(i-1)) / i;
    }
    // We add the last divisor, n
    ans += n;
    ans %= MOD;

    cout << ans << endl;
   
    return 0;
}
