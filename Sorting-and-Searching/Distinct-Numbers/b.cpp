#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set<ll> nums;
    for(int i = 0; i< n; i++){
        int x;
        cin >> x;
        nums.insert(x);
    }
    cout << nums.size() << endl;
    return 0;
}
