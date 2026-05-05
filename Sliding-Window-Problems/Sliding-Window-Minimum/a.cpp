#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int k, n;
ll x, a, b;
int mod;
vector<ll> nums;

void gen(){
    nums.resize(n);
    nums[0] = x;
    for(int i =1 ; i < n; i++)
        nums[i] = (nums[i-1] *a +b) %mod;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    cin >> x >> a >> b >> mod;
    gen();
    multiset<ll> ms;
    for(int i = 0; i < k; i++){
        ms.insert(nums[i]);
    }
    ll ans = *ms.begin();
    for(int i = k; i < n; i++){
        ms.insert(nums[i]);
        ms.erase(nums[i-k]);
        ans ^= *ms.begin();
    }
    cout << ans << endl;
    return 0;
}
