#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    cout << 0 << "\n";
    for(ll i = 1; i<n; i++)
        cout << (i)*(i+5)*(i*i -i+2)/2 << "\n"; 
    return 0;
}
