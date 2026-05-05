#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> nums;
ll a,b,n,k,x;
int mod;

void gen(){
    nums.resize(n);
    nums[0] = x;
    for(int i = 1; i < n; i++){
        nums[i] = (a*nums[i-1] +b) % mod;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    cin >> x >> a >> b;
    cin >> mod;
    gen();
    ll sum = 0;
    for(int i = 0; i < k; i++){
        sum += nums[i]; 
    }
    ll ans = sum;
    for(int i = k; i < n;i++){
        sum += nums[i];
        sum -= nums[i-k];
        ans ^=sum;
    }
    cout << ans << endl;
    return 0;
}
