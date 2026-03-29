#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
vector<ll> fact(2e6+2, 1);

ll binpow(ll a, ll b){
    if(b == 0)
        return 1 % MOD;
    if(b & 1)
        return (a * binpow(a, b-1)) % MOD;
    ll res = binpow(a, b/2);
    return (res * res) % MOD;
}

ll mod_inv(ll a){
    return binpow(a, MOD-2);
}

ll comb(ll a, ll b){
    return (fact[a] * mod_inv((fact[b] * fact[a-b])% MOD)) % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    for(int i = 1; i<=n+m; i++)
        fact[i] = (fact[i-1] * i) % MOD;
    cout << comb(n+m-1, m) << endl;
    return 0;
}
