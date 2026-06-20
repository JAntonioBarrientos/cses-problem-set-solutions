#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> nums;
int n, k;
ll x, a, b, c;

void gen(){
    nums[0] = x;
    for(int i = 1; i < n; i++){
        nums[i] = (a * nums[i-1] + b) % c;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    cin >> x >> a >> b >> c;
    nums.resize(n);
    gen();
    deque<int> dq;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(!dq.empty() and dq.front()==i-k){
            dq.pop_front();
        }
        while(!dq.empty() and nums[dq.back()] >= nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i >= k-1){
            ans ^= nums[dq.front()];
        }
    }
    cout << ans << endl;
    return 0;
}

