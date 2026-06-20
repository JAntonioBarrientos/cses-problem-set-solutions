#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> nums;

ll f(int x){
    ll ans = 0;
    for(auto n: nums){
        ans += abs(n-x);
    }
    return ans;
}

ll ter_search(ll l, ll r){
    while(r-l>=3){
        ll m1 = l + (r-l)/3;
        ll m2 = r - (r-l)/3;
        ll fm1 = f(m1);
        ll fm2 = f(m2);
        if(fm1 == fm2){
            l = m1;
            r = m2;
        }
        else if(fm1 > fm2){
            l = m1;
        }
        else{
            r = m2;
        }
    }
    ll ans = f(l);
    for(int i = l+1; i <=r; i++){
        ans = min(ans, f(i));
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    nums.resize(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    ll ans = ter_search(0, 1e9+1); 
    cout << ans << endl;
    return 0;
}
