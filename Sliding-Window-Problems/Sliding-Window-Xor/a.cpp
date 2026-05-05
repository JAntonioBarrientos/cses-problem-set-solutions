#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll k,n, a,b,x;
int c;
vector<ll> nums;

void gen(){
    nums[0]= x;
    for(int i = 1; i < n; i++){
        nums[i] = (nums[i-1] * a +b) % c;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    cin >> x >> a >> b >> c;
    nums.resize(n);
    gen();
    ll win= 0;
    for(int i = 0; i < k; i++){
        win^=nums[i];
    }
    ll ans = win;
    for(int i = k; i <n; i++){
        win ^=nums[i];
        win ^= nums[i-k];
        ans ^= win;
    }
    cout << ans << endl;
    return 0;
}
