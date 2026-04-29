#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> time(n);
    for(auto &x: time)
        cin >> x;
    sort(time.begin(), time.end());
    ll suma = 0;
    ll larg = 0;
    for(int i = 0; i < time.size(); i++){
        suma += time[i];
        larg = max(larg, time[i]);
    }
    cout << max(larg*2, suma) << endl;
   
    return 0;
}
