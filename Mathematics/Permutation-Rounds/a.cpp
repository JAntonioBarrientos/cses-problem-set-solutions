#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int N = 1e6;
vector<bool> is_prime(N,true);
vector<int> primes;

void criba(){
    is_prime[1] = false;
    is_prime[0] = false;
    for(int i = 2; i < N; i++){
        if(is_prime[i]){
            primes.push_back(i);
            for(ll j = 1LL * i*i; j < N; j+=i){
                is_prime[j] = false;
            }
        }
    }
}


ll binpow(ll a, ll b){
    if(b == 0){
        return 1;
    }
    if(b & 1)
        return (a * binpow(a,b-1)) % MOD;
    ll res = binpow(a,b/2);
    return (res * res) % MOD;
}

map<int,int> factor(ll x){
    int temp = x;
    map<int,int> ans;
    for(int p: primes){
        while(temp % p == 0){
            ans[p]++;
            temp /=p;
        }
        if(temp == 1)
            return ans;
    }
    return ans;
}


ll lcm_mod(const vector<ll> &nums, int n){
    map<int,int> ans;
    for(int i = 0; i < n; i++){
        map<int,int> curr = factor(nums[i]);
        for(auto &[prime, exp]: curr){
            auto it = ans.find(prime);
            if(it!=ans.end()){
                it->second = max(exp, it->second);
            }
            else{
                ans[prime] = exp;
            }
        }
    }
    ll lcm=1;
    for(auto &[prime, exp]: ans){
        lcm = (lcm * binpow(prime, exp))% MOD;
    }
    return lcm;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto &x: nums){
        cin >> x;
        x--;
    }
    criba();
    if(n == 1){
        cout << 1;
        return 0;
    }
    vector<bool> vis(n);
    vector<ll> lengths;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            int current = i;
            int length = 0;
            while(!vis[current]){
                vis[current] = true;
                current = nums[current];
                length++;
            }
            lengths.push_back(length);
        }
    }
    ll ans = lcm_mod(lengths,lengths.size());
    cout << ans << endl;
    return 0;
}
