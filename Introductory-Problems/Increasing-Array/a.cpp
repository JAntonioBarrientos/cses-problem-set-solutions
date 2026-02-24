#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; 
    cin >> n;
    int prev;
    cin >> prev;
    ll ans = 0;
    int curr;
    for(int i = 1; i < n; i++){
        cin >> curr;
        prev = max(prev, curr);
        ans += prev-curr;
    }
    cout << ans << endl;
    return 0;
}
