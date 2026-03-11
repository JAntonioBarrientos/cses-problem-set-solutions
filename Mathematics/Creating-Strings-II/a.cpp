#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

ll binpow(ll a, ll b){
    if(b == 0)
        return 1;
    if(b & 1)
        return (a * binpow(a, b-1)) % MOD;
    ll res = binpow(a, b/2);
    return (res * res) % MOD;
}

ll mod_inv(ll a){
    return binpow(a, MOD-2);
}

vector<ll> fact(1e6+1);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    vector<int> freq(26);
    int n = s.size();
    for(char c: s){
        freq[c-'a']++;
    }
    fact[0] = 1;
    for(int i = 1; i <=n; i++)
        fact[i] = (fact[i-1] * i) % MOD;
    ll denominador = 1;
    for(int i = 0; i < freq.size(); i++)
        denominador = (denominador * fact[freq[i]] ) % MOD;
    ll res = (fact[n] * mod_inv(denominador)) % MOD;
    cout << res << endl;
    return 0;
}
