#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    int n;
    cin >> n;
    int ans = 0;
    int base = 5;
    while(base <= n){
        for(int i = base; i <= n; i+=base){
            ans++;
        }
        base *=5;
    }
    cout << ans << "\n";
    return 0;
}
