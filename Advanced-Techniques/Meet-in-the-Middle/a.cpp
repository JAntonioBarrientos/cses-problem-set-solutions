#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
int x;
vector<int> nums;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> x;
    nums.resize(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int m = n/2;
    vector<ll> sum1;
    for(int i = 0; i < (1<<m) ; i++){
        ll s = 0;
        for(int j = 0; j < m; j++){
            if(i & (1<<j)){
                s += nums[j];
            }
        }
        sum1.push_back(s);
    }
    sort(sum1.begin(), sum1.end());
    ll ans = 0;
    for(int i = 0; i < (1<<(n-m)) ; i++){
        ll s = 0;
        for(int j = 0; j < n-m; j++){
            if(i & (1<<j)){
                s += nums[m+j];
            }
        }
        ll diff = x-s;
        auto it1 = upper_bound(sum1.begin(), sum1.end(), diff);
        auto it2 = lower_bound(sum1.begin(), sum1.end(), diff);
        ans += it1-it2;
    }
    cout << ans << endl;
    return 0;
}
