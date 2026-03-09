#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(int a, int b){
    if(2*a >= b and 2*b >= a and (2*a-b) % 3 == 0){
        cout << "YES" << "\n";
        return;
    }
    cout << "NO" << "\n";
    return;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        solve(a,b);
    }
    return 0;
}
