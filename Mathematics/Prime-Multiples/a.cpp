#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e18;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, k; 
    cin >> n >> k;
    vector<ll> primes(k);
    for(int i = 0; i <k ; i++)
        cin >> primes[i];
    ll ans = 0;
    int cnt = 0;
    ll temp;
    for(int b = 1; b <(1<<k); b++){
        temp =1;
        cnt = 0;
        for(int j = 0; j <k; j++){
            if(b & (1<<j)){
                temp *= primes[j];
                cnt++;
            }
        }
        if(cnt % 2 == 0){
            ans -= n/temp;
        }
        else{
            ans += n/temp;
        }
    }
    cout << ans << endl;
    return 0;
}
