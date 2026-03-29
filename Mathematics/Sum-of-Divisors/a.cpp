#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll ans = 1+n;
    int m = n;
    for(int i = 2; i*i <= m; i++){
        while(n % i == 0){
            ans+= i;
            ans%= MOD;
            if(n/i != i){
                ans += n/i;
                ans %= MOD;
            }
            n /= i;
        }
    }

    cout << ans << endl;
   
    return 0;
}
