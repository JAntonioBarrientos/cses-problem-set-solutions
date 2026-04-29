#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, x;
    cin >> n >> x;
    vector<ll> nums(n);
    for(int i= 0; i <n; i++){
        cin >> nums[i];
    }
    vector<ll> prefix(n+1);
    prefix[0] = 0;
    for(int i = 1; i <= n; i++){
        prefix[i] = nums[i-1]+ prefix[i-1];
    }
    multiset<ll> ms;
    for(auto p: prefix){
        ms.insert(p);
    }
    ll cnt = 0;
    for(int i = 0; i <= n; i++){
        if(ms.count(x+prefix[i]) > 0){
            cnt += ms.count(x+prefix[i]);
        }
        ms.erase(prefix[i]);
    }
    cout << cnt << endl;
    return 0;
}
