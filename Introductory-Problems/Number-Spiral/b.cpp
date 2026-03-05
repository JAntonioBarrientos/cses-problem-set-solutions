#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll x, y;
    cin >> y >> x;
    ll maxi = max(x,y);
    ll ans = maxi*maxi - maxi +1;
    ll diff = x-y;
    if(maxi % 2 == 0){
        ans -= diff;
    }
    else{
        ans += diff;
    }
    cout << ans << "\n";
    return;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
