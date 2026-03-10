#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
vector<ll> fact(1e6+1);

ll binpow(ll a, ll b){
    if(b == 0)
        return 1;
    if(b & 1)
        return (a * binpow(a, b-1) ) % MOD;
    ll res = binpow(a, b/2);
    return (res * res) %MOD;
}

ll mod_inv(ll x){
    return binpow(x, MOD-2);
}

ll binomial(ll a, ll b){
    return (fact[a]* mod_inv((fact[a-b] *fact[b])%MOD))% MOD; 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll a,b;
    fact[0] = 1;
    for(int i = 1; i <= 1e6; i++)
        fact[i] = (fact[i-1] * i) %MOD;
    while(n--){
        cin >> a >> b;
        cout << binomial(a,b) << "\n";
    }
    return 0;
}
