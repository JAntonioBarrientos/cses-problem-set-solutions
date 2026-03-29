#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
vector<ll> fact(1e6+1, 1);

ll binpow(ll a, ll b){
    if(b== 0)
        return 1;
    if(b&1) 
        return (a * binpow(a, b-1) ) %MOD;
    ll res = binpow(a, b/2);
    return (res * res) % MOD;
}

ll mod_inv(ll a){
    return binpow(a, MOD-2);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        fact[i] = (fact[i-1] * i ) % MOD;
    ll sum = 0;
    ll sign = 1;
    for(int i = 2; i <= n; i++){
        sum = (((sum + sign*mod_inv(fact[i])) % MOD) + MOD) % MOD;
        sign *= -1; 
    }
    ll ans = (fact[n] * sum) % MOD;
    cout << ans << endl; 
    return 0;
}
