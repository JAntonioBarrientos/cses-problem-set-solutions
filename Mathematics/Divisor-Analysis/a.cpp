#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
vector<pair<ll,ll>> num;
vector<ll> tau;

ll s_n(ll n){
    return (n * (n+1)) / 2;
}

ll binpow(ll a, ll b, ll mod){
    ll ans = 1; 
    while(b > 0){
        if(b & 1)
            ans = (ans * a) % mod;
        a= (a*a) % mod;
        b >>= 1;
    }
    return ans;
}

ll mod_inv(ll a, ll mod){
    return binpow(a, mod-2, mod);
}

ll sum_of_div(){
    int n = num.size();
    ll nume= 1;
    ll deno = 1;
    for(int i = 0; i < n; i++){
        nume= (nume * (binpow(num[i].first, num[i].second+1, MOD) - 1)) % MOD; 
        deno= (deno * (num[i].first-1) ) % MOD;
    }
    return (nume * mod_inv(deno, MOD)) % MOD;
}

ll num_of_div(){
    ll ans = 1;
    int n = num.size();
    for(int i =0; i <n ;i++){
        ans = (ans * (num[i].second +1)) % MOD;
    }
    return ans;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int x,k;
    for(int i = 0; i<n;i++){
        cin >> x >> k;
        num.emplace_back(x,k);
    }
    cout << num_of_div() << " ";
    cout << sum_of_div() << " ";

    tau.assign(n, 0);
    // Since the order of the elem in the group is p-1
    ll mod_exp= MOD-1;
    tau[n-1] = 1;
    for(int i = n-2; i>= 0; i--){
        tau[i] = (tau[i+1] * (num[i+1].second+1)) % mod_exp;
    }
    ll multiplier = 1;
    ll product = 1;
    for(int i = 0; i < n; i++){
        ll base = num[i].first;
        ll power = s_n(num[i].second) % mod_exp;
        power = (power * tau[i]) % mod_exp; 
        power = (power * multiplier) % mod_exp;
        product = (product * binpow(base, power, MOD)) % MOD;
        multiplier = (multiplier * (num[i].second +1)) % mod_exp;
    }
    cout << product << endl;
   
    return 0;
}
