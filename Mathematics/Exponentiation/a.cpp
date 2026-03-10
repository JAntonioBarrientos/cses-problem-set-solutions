#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

ll binpow(ll a, ll b){
    if(b == 0)
        return 1;
    if(b & 1)
        return (a * binpow(a, b-1)) %MOD;
    ll res = binpow(a, b/2);
    return (res * res) % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    int n;
    cin >> n;
    while(n--){
        ll a,b;
        cin >> a >> b;
        cout << binpow(a,b) << "\n";
    }

    return 0;
}
