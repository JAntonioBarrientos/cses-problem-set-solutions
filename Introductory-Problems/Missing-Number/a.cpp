#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll sum = 0;
    ll total = 1;
    int n;
    
    cin >> n;

    ll x;
    for(int i = 2; i<=n; i++){
        cin >> x;
        sum+=x;
        total +=i;
    }

    cout << total - sum << endl;

    return 0;
}
