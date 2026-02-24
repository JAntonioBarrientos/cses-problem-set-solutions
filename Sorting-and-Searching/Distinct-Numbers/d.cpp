#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> nums(n, 0);
    for(int i = 0; i< n; i++){
        int x;
        cin >> x;
        nums[i] = x;
    }
    sort(nums.begin(), nums.end());
    auto it = unique(nums.begin(), nums.end());
    int total = it - nums.begin();  
    cout << total << endl;
    return 0;
}

