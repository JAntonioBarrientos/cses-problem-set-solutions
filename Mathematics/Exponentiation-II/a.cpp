#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

ll binpow(ll a, ll b, ll mod){
    if(b == 0)
        return 1 % mod;
    if(b & 1)
        return (a * binpow(a,b-1, mod) ) % mod;
    ll res = binpow(a, b/2, mod);
    return (res * res) % mod;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        ll a,b,c;
        cin >> a >> b >> c;
        ll order_a = MOD - 1;
        cout << binpow(a, binpow(b, c, order_a), MOD) << "\n"; 
    }
    return 0;
}
